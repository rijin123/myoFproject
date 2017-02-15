#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//��ʃT�C�Y
	ofSetWindowShape(1280, 720);
	ofSetFrameRate(60);

	video.loadMovie("douga.mp4");
	video.setLoopState(OF_LOOP_NORMAL);
	video.play();

	//���{������[�h
	font.loadFont("msmincho.ttc", fontSize);

	//�e�L�X�g�t�@�C������̓ǂݍ���
	ofBuffer buffer = ofBufferFromFile("note.txt"); // reading into the buffer
	mes = buffer.getText();

	for (int i = 0; i < NUM;i++) {
		//x:�����̗�ł̊Ԋu,y:�����̗�
		position[i] = ofVec2f(ofGetWidth() / 2 - 300+i*ofRandom(10,300)
			, ofGetHeight() / 2 + (i - 7) * 40);		
		velocity[i] = ofVec2f(100 , 0);
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	
	//�E���獶�ɗ����
	for (int i = 0; i < NUM;i++) {
		position[i] -= velocity[i];
		// ��ʂ̍��O�ɂł���A�E���痬���
		if (position[i].x < -800) {
			position[i].x = ofGetWidth() - 300;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	video.draw(0, 0);
	//�����̕��������h��
	for (int i = 0; i < NUM;i++) {
		ofSetColor(0, 0, 0);
		for (int y = -7; y < 7; y++) {
			for (int x = -7; x < 7; x++) {
				font.drawString(mes, position[i].x + x, position[i].y + y);
			}
		}
		// ����ɂ��́A�ƕ\������
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
