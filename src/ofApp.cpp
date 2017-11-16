      #include "ofApp.h"


float threeFourTime_x;
float fourFourTime_x;
float fiveFourTime_x;

float threeFourTime[81];
float fourFourTime[61];
float fiveFourTime[49];

int threeFourTimeColor[81];
int fourFourTimeColor[81];
int fiveFourTimeColor[81];


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1800, 768);
    ofBackground(255);
    
    for (int i = 0; i < 80; i++) {
        threeFourTime[i] = (float)i * (60.0/80.0);
    }
    
    for (int i = 0; i < 60; i++) {
        fourFourTime[i] = (float)i * (60.0/60.0);
    }

    for (int i = 0; i < 48; i++) {
        fiveFourTime[i] = (float)i * (60.0/48.0);
    }
    
    threeFourTime_x = (ofGetWidth() - 100.0) / 80.0;
    fourFourTime_x = (ofGetWidth() - 100.0) / 60.0;
    fiveFourTime_x = (ofGetWidth() - 100.0) / 48.0;
    
    // 1 ... 3/4 == 4/4
    // 2 ... 4/4 == 5/4
    // 3 ... 3/4 == 5/4
    // 4 ... all
    for (int i = 0; i < 81; i++) {
        for (int k = 0; k < 49; k++) {
            if (fabsf(threeFourTime[i] - fiveFourTime[k]) < FLT_EPSILON){
                threeFourTimeColor[i] = 3;
            }
        }
        for (int j = 0; j < 61; j++ ){
            if (fabsf(threeFourTime[i] - fourFourTime[j]) < FLT_EPSILON){
                threeFourTimeColor[i] = 1;
            }
            if (fabsf(threeFourTime[i] - fourFourTime[j]) < FLT_EPSILON){
                for (int k =0; k < 49; k++) {
                    if(fabsf(threeFourTime[i] - fiveFourTime[k]) < FLT_EPSILON){
                        threeFourTimeColor[i] = 4;
                    }
                }
            }
        }
    }
    
    for (int j = 0; j < 61; j++) {
        for (int k = 0; k < 49; k++) {
            if (fabsf(fourFourTime[j] - fiveFourTime[k]) < FLT_EPSILON){
                fourFourTimeColor[j] = 2;
            }
        }
        for (int i = 0; i < 81; i++ ){
            if (fabsf(fourFourTime[j] - threeFourTime[i]) < FLT_EPSILON){
                fourFourTimeColor[j] = 1;
            }
            if (fabsf(fourFourTime[j] - threeFourTime[i]) < FLT_EPSILON){
                for (int k =0; k < 49; k++) {
                    if(fabsf(fourFourTime[j] - fiveFourTime[k]) < FLT_EPSILON){
                        fourFourTimeColor[j] = 4;
                    }
                }
            }
        }
    }
    
    for (int k = 0; k < 49; k++) {
        for (int j = 1; j < 61; j++) {
            if (fabsf(fiveFourTime[k] - fourFourTime[j]) < FLT_EPSILON){
                fiveFourTimeColor[k] = 2;
            }
        }
        for (int i = 0; i < 81; i++ ){
            if (fabsf(fiveFourTime[k] - threeFourTime[i]) < FLT_EPSILON){
                fiveFourTimeColor[k] = 3;
            }
            if (fabsf(fiveFourTime[k] - threeFourTime[i]) < FLT_EPSILON){
                for (int j =0; j < 61; j++) {
                    if(fabsf(fiveFourTime[k] - fourFourTime[j]) < FLT_EPSILON){
                        fiveFourTimeColor[k] = 4;
                    }
                }
            }
        }
    }

    
    
    for (int i = 0; i < 81; i++) {
        std::cout << i <<": " << threeFourTimeColor[i] << std::endl;
    }
//    std::cout << fourFourTimeColor[81] << std::endl;
//    std::cout << fiveFourTimeColor[81] << std::endl;
//

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetLineWidth(5);
    
    for (int i = 0; i < 81; i++) {
        switch (threeFourTimeColor[i]) {
            case 1:
                ofSetColor(255, 100, 0);
                break;
            case 2:
                ofSetColor(0, 255, 0);
                break;
            case 3:
                ofSetColor(0, 0, 255);
                break;
            case 4:
                ofSetColor(255, 0, 0);
                break;
            default:
                ofSetColor(128, 128, 128);
                break;
        }
        
        if (i % 4 == 0){
            ofDrawLine(i * threeFourTime_x + 50, 10, i * threeFourTime_x + 50, 100);
        } else {
            ofDrawLine(i * threeFourTime_x + 50, 30, i * threeFourTime_x + 50, 80);
        }
        
        ofSetColor(0);
        if (i % 2 == 0) {
            ofDrawBitmapString(ofToString(threeFourTime[i]+1), i * threeFourTime_x + 45, 110);
        } else {
            ofDrawBitmapString(ofToString(threeFourTime[i]+1), i * threeFourTime_x + 45, 125);
        }

    }
    
    for (int i = 0; i < 61; i++) {
        switch (fourFourTimeColor[i]) {
            case 1:
                ofSetColor(255, 100, 0);
                break;
            case 2:
                ofSetColor(0, 255, 0);
                break;
            case 3:
                ofSetColor(0, 0, 255);
                break;
            case 4:
                ofSetColor(255, 0, 0);
                break;
            default:
                ofSetColor(128, 128, 128);
                break;
        }
        
        if (i % 4 == 0){
            ofDrawLine(i * fourFourTime_x + 50, 140, i * fourFourTime_x + 50, 240);
        } else {
            ofDrawLine(i * fourFourTime_x + 50, 160, i * fourFourTime_x + 50, 220);

        }
        
        ofSetColor(0);
        if (i % 2 == 0) {
            ofDrawBitmapString(ofToString(fourFourTime[i]+1), i * fourFourTime_x + 45, 250);
        } else {
            ofDrawBitmapString(ofToString(fourFourTime[i]+1), i * fourFourTime_x + 45, 265);
        }
    }
    
    for (int i = 0; i < 49; i++) {
        switch (fiveFourTimeColor[i]) {
            case 1:
                ofSetColor(255, 100, 0);
                break;
            case 2:
                ofSetColor(0, 255, 0);
                break;
            case 3:
                ofSetColor(0, 0, 255);
                break;
            case 4:
                ofSetColor(255, 0, 0);
                break;
            default:
                ofSetColor(128, 128, 128);
                break;
        }
        
        if (i % 4 == 0){
            ofDrawLine(i * fiveFourTime_x + 50, 280, i * fiveFourTime_x + 50, 380);
        } else {
            ofDrawLine(i * fiveFourTime_x + 50, 300, i * fiveFourTime_x + 50, 360);
        }
        
        ofSetColor(0);
        if (i % 2 == 0) {
            ofDrawBitmapString(ofToString(fiveFourTime[i]+1), i * fiveFourTime_x + 45, 390);
        } else {
            ofDrawBitmapString(ofToString(fiveFourTime[i]+1), i * fiveFourTime_x + 45, 405);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
