#include "Settings.h"


DecisionArgs Args = { GINI_NORMAL };

int main(int argc, char* args[]) {
    
    /*strcpy(Args.pathForest, "../Datasets/MNIST_t20_9485.txt");
    strcpy(Args.trainPath, "../Datasets/MNIST_train.txt");
    strcpy(Args.testPath, "../Datasets/MNIST_test.txt");
    StartTest();*/
    strcpy(Args.trainPath, "../Datasets/MNIST_train_filtered.txt");
    strcpy(Args.testPath, "../Datasets/MNIST_test_filtered.txt");
    Args.isSilent = true;
    Args.treeCount = 30;
    Args.maxDepth = 25;
    /*Args.useFeatureBagging = true;
    Args.featureBaggingProportion = 0.94;
    Args.useInstanceBagging = true;
    Args.instanceBaggingProportion = 0.88;*/
    //Args.prunningThreshold = 1.f;
    //test_random_forest(Args.trainPath, Args.testPath, 10);

    SearchHyperParametersOfRandomForest();

    return 0;
}