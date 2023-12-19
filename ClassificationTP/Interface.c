#include "Settings.h"


const int images_shade_of_white[] = { 10, 50, 80, 120, 190, 220 };


SDL_Window* initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't intialize SDL_Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow("Paint AI", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("COund't create window SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    return window;
}

void drawPainterPixel(SDL_Renderer* renderer, int x, int y, int color) {
    SDL_SetRenderDrawColor(renderer, color, color, color, 255);

    SDL_Rect rect;
    rect.x = IMAGE_PIXEL_SIZE * x;
    rect.y = IMAGE_PIXEL_SIZE * y;
    rect.w = IMAGE_PIXEL_SIZE;
    rect.h = IMAGE_PIXEL_SIZE;

    SDL_RenderFillRect(renderer, &rect);
}


Input getInputs() {
    SDL_Event event;
    Input input = { .isMouseClick = false, .quit = false };

    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
        case SDL_MOUSEMOTION : {
            if (event.button.button != SDL_BUTTON_MIDDLE) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                input.isMouseClick = event.button.button > 0;
                input.mouseButton = event.button.button;
                input.mouseX = mouseX;
                input.mouseY = mouseY;
            }
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            input.isMouseClick = event.button.button > 0;
            input.mouseButton = event.button.button;
            input.mouseX = mouseX;
            input.mouseY = mouseY;
            break;
        }
        //case SDL_MOUSEBUTTONUP: {
        //    //if ()
        //    break;
        //}
        }

        if (event.type == SDL_QUIT) {
            input.quit = true;
        }
    }

    return input;
}

void applyConvolution(int matrix[FEATURES_COUNT][FEATURES_COUNT], int x, int y) {
    if (x >= FEATURES_COUNT || y >= FEATURES_COUNT || x < 0 || y < 0) return;
    int sum = 0;
    int sumXY = 0;

    for (int x1 = -1; x1 < 2; x1++) {
        int xt = (x + x1);
        
        if (xt < 0 || xt >= FEATURES_COUNT) continue;
        for (int y1 = -1; y1 < 2; y1++) {
            int yt = (y + y1);
            if (yt < 0 || yt >= FEATURES_COUNT) continue;
            sum += matrix[xt][yt];
            sumXY++;
        }
    }

    if (matrix[x][y] != 255)
        matrix[x][y] = sum / sumXY;
}

void updatePaintMatrix(Input input, int matrix[FEATURES_COUNT][FEATURES_COUNT]) {
    if (!input.isMouseClick) return;

    int x = (int)((float)input.mouseX * (float)FEATURES_COUNT / (float)PAINT_RECT_SIZE);
    int y = (int)((float)input.mouseY * (float)FEATURES_COUNT / (float)PAINT_RECT_SIZE);

    if (x >= FEATURES_COUNT || y >= FEATURES_COUNT || x < 0 || y < 0) return;

    if (input.mouseButton == SDL_BUTTON_LEFT) {
        matrix[x][y] = 255;
        applyConvolution(matrix, x-1, y-1);
        applyConvolution(matrix, x, y-1);
        applyConvolution(matrix, x+1, y-1);
        applyConvolution(matrix, x-1, y);
        applyConvolution(matrix, x+1, y);
        applyConvolution(matrix, x+1, y-1);
        applyConvolution(matrix, x+1, y);
        applyConvolution(matrix, x+1, y+1);
    }
    else {
        matrix[x][y] = 0;
    }
}

void RunSdl(RandomForest *rf) {
    SDL_Window* window = initSDL();
    if (window == NULL) {
        exit(1);
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    Input input = { .quit = false };
    int matrix[FEATURES_COUNT][FEATURES_COUNT] = { 0 };


    while (!input.quit) {
        input = getInputs();

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        /*
        When u middle mouse click, it reset the matrix to black
        */
        if (input.mouseButton == SDL_BUTTON_MIDDLE) {
            Instance *instance = calloc(1, sizeof(Instance));
            instance->values = (int*)calloc(FEATURES_COUNT * FEATURES_COUNT, sizeof(int));

            for (int x = 0; x < FEATURES_COUNT; x++) {
                for (int y = 0; y < FEATURES_COUNT; y++) {
                    instance->values[(x * FEATURES_COUNT) + y] = matrix[x][y];
                }
            }
            
            int prediction = RandomForest_predict(rf, instance);
            printf("predict: %d\n", prediction);

            for (int x = 0; x < FEATURES_COUNT; x++) {
                for (int y = 0; y < FEATURES_COUNT; y++) {
                    matrix[x][y] = 0;
                }
            }
        }
        else
            updatePaintMatrix(input, matrix);
        
            
        for (int x = 0; x < FEATURES_COUNT; x++) {
            for (int y = 0; y < FEATURES_COUNT; y++) {
                drawPainterPixel(renderer, x, y,matrix[x][y]);
            }
        }


        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}