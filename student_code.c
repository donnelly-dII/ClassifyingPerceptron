#include "constants.c"
float calcObjective(float w0, float w1, float c, float x, float y){return w0*x + w1*y + c;}

float predictionCalc(float w0, float w1, float c, float x, float y){
	float pred = calcObjective(w0,w1,c,x,y);
	if(pred >= 0){
		return 1;
	}
	else{
		return 0;
	}
}

float TrainSuccess(float w0, float w1, float c, float **data_train){
	float correct = 0;
	for(int ii = 0; ii < TRAINING_SIZE; ii++){
		float predHold = predictionCalc(w0,w1,c,data_train[ii][0],data_train[ii][1]);
		if (predHold == data_train[ii][2]){
			correct++;
		}
	}
	return correct;
}

void part_one_classifier(float **data_train,float **data_test)
{
	//initialize weights
	float w0 = 0, w1 = 0, c=0, succRate = 0;
	int iterCount = 0;
	while(succRate < .95 && iterCount < 100){
		for(int ii = 0; ii < TRAINING_SIZE; ii++){
			float xHold = data_train[ii][0];
			float yHold = data_train[ii][1];
			float labHold = data_train[ii][2];
			float predict = predictionCalc(w0,w1,c,xHold, yHold);
			c = c + (labHold - predict) * (w0 * xHold + yHold * w1);
			w0 = w0 + (labHold - predict) * xHold;
			w1 = w1 + (labHold - predict) * yHold;
		}
		succRate = TrainSuccess(w0,w1,c,data_train)/TRAINING_SIZE;
		iterCount++;
	}
	//Fill in the Rows
	for(int ii = 0; ii < TEST_SIZE; ii++){
		data_test[ii][2] = predictionCalc(w0, w1, c, data_test[ii][0], data_test[ii][1]);
	}

}

void part_two_classifier(float **data_train,float **data_test)
{
	// PUT YOUR CODE HERE
	// Access the training data using "data_train[i][j]"
	// Training data contains 3 cols per row: X in 
	// index 0, Y in index 1 and Class in index 2
	// Access the test data using "data_test[i][j]"
	// Test data contains 2 cols per row: X in 
	// index 0 and Y in index 1, and a blank space in index 2 
	// to be filled with class
	// The class value could be a 0 or a 8
    
    //I AM EDITING THIS
}
