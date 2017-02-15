#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//画面サイズ
	ofSetWindowShape(1280, 720);
	ofSetFrameRate(60);

	video.loadMovie("douga.mp4");
	video.setLoopState(OF_LOOP_NORMAL);
	video.play();

	//日本語をロード
	font.loadFont("msmincho.ttc", fontSize);

	//テキストファイルからの読み込み
	ofBuffer buffer = ofBufferFromFile("note.txt"); // reading into the buffer
	mes = buffer.getText();

	for (int i = 0; i < NUM;i++) {
		//x:文字の列での間隔,y:文字の列
		position[i] = ofVec2f(ofGetWidth() / 2 - 300+i*ofRandom(10,300)
			, ofGetHeight() / 2 + (i - 7) * 40);		
		velocity[i] = ofVec2f(100 , 0);
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	
	//右から左に流れる
	for (int i = 0; i < NUM;i++) {
		position[i] -= velocity[i];
		// 画面の左外にでたら、右から流れる
		if (position[i].x < -800) {
			position[i].x = ofGetWidth() - 300;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	video.draw(0, 0);
	//文字の淵を黒く塗る
	for (int i = 0; i < NUM;i++) {
		ofSetColor(0, 0, 0);
		for (int y = -7; y < 7; y++) {
			for (int x = -7; x < 7; x++) {
				font.drawString(mes, position[i].x + x, position[i].y + y);
			}
		}
		// こんにちは、と表示する
		ofSetColor(255);
		font.drawString(mes, position[i].x, position[i].y);
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
