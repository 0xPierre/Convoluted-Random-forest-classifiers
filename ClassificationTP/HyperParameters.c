#include "Settings.h"



void SearchHyperParametersOfRandomForest() {
	printf("Load dataset from file: %s\n", Args.trainPath);
	Dataset *trainData = Dataset_readFromFile(Args.trainPath);
	printf("Load dataset from file: %s\n", Args.testPath);
	Dataset *testData = Dataset_readFromFile(Args.testPath);

	printf("Calculate subproblem\n");
	Subproblem *subproblem = Dataset_getSubproblem(trainData);

	// Force the random forest to use features bagging
	Args.useFeatureBagging = true;
	Args.useInstanceBagging = true;

	float bestAccuracy = 0.f;
	float bestThreshold = 0.f;
	float bestFeaturesBagging = 0.f;
	float bestInstancesBagging = 0.f;
	RandomForest *bestRandomForest = NULL;

	float minThreshold = 0.99f;
	float maxThreshold = 0.99f;
	float minFeaturesBagging = 0.05f;
	float maxFeaturesBagging = 0.08f;
	float minInstancesBagging = 1.f;
	float maxInstancesBagging = 1.f;

	printf("Starting search using %f-%f %f-%f %f-%f\n", minThreshold, maxThreshold, minFeaturesBagging, maxFeaturesBagging, minInstancesBagging, maxInstancesBagging);
	// Search for best threshold
	for (float threshold = minThreshold; threshold <= maxThreshold; threshold += 0.01f) {

		// Search for best features bagging
		for (float featuresBagging = minFeaturesBagging; featuresBagging <= maxFeaturesBagging; featuresBagging += 0.01f) {
			Args.featureBaggingProportion = featuresBagging;

			// Search for the best instances bagging
			for (float instancesBagging = minInstancesBagging; instancesBagging <= maxInstancesBagging; instancesBagging += 0.01f) {
				Args.instanceBaggingProportion = instancesBagging;
				// Remise � z�ro des randoms
				srand(0);
				// Create random forest
				RandomForest* rf = RandomForest_create(Args.treeCount, trainData, Args.maxDepth, instancesBagging, threshold);
				float score = RandomForest_evaluate(rf, testData);

				if (score > bestAccuracy) {
					if (bestRandomForest != NULL)
						free(bestRandomForest);

					bestRandomForest = rf;
					bestAccuracy = score;
					bestThreshold = threshold;
					bestFeaturesBagging = featuresBagging;
					bestInstancesBagging = instancesBagging;
					printf("Best score: %.4f | %.2f %.2f %.2f\n", score, threshold, featuresBagging, instancesBagging);
				}
				else {
					free(rf);
				}
				printf("%.2f %.2f %.2f | score: %f\n", threshold, featuresBagging, instancesBagging, score);
			}
		}
	}

	printf("Results:\n");
	printf("Best accuracy: %f\n", bestAccuracy);
	printf("Best threshold: %f\n", bestThreshold);
	printf("Best features bagging: %f\n", bestFeaturesBagging);
	printf("Best instances bagging: %f\n", bestInstancesBagging);
	printf("Node count %d\n", RandomForest_nodeCount(bestRandomForest));

	ForestFileDump(bestRandomForest, "BEST_FOREST_SAVED.dfm");

	Dataset_destroy(trainData);
	Dataset_destroy(testData);
	Subproblem_destroy(subproblem);
}