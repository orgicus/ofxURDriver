//
//  KinectModel.h
//  urModernDriverTest
//
//  Created by dantheman on 2/20/16.
// Copyright (c) 2016, Daniel Moore, Madaline Gannon, and The Frank-Ratchye STUDIO for Creative Inquiry All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "Synchronized.h"
//#include "ofxBullet.h"

enum RobotType{
    UR3,
    UR5,
    UR10
};

struct Joint{
    ofVec3f offset;
    ofVec3f axis;
    ofVec3f position;
    ofQuaternion rotation;
};

class URKinematicModel{
public:
    URKinematicModel();
    ~URKinematicModel();
    void setup();
    void setupUR3();
    void setupUR5();
    void setupUR10();
    void setup(RobotType m);
    void update();
    void draw(float stage = 3.0);
    void setToolMesh(ofMesh mesh);
    ofNode getTool();
    void setToolOffset(ofVec3f localOffset);
    ofQuaternion getToolPointQuaternion();
    
    ofxAssimpModelLoader loader;
    vector<ofMesh> meshs;
    ofMesh toolMesh;
    
    ofShader shader;
    float elapsed_time, last_time;
    ofVec3f pt;
    vector<Joint> joints;
    Synchronized<vector<double> > jointsProcessed;
    Synchronized<vector<double> > jointsRaw;
    Synchronized<vector<double> > toolPointRaw;
    Joint tool;
    
    Joint dtoolPoint;
    
    ofEasyCam cam;
    ofNode tcpNode;
    vector<ofNode> nodes;
    
    ofParameter<float> stage;
    ofParameter<bool> bDrawModel;
    ofParameter<bool> bDrawTargetModel;
    
    
    
//    ofxBulletWorldRigid			world;
//    vector <ofxBulletBox*>		bounds;
//    ofxBulletCustomShape*		boundsShape;
//    
//    vector<ofxBulletCustomShape*>	phyMesh;
//    vector<ofxBulletJoint*>		phyJoints;
    
//private:
    RobotType type;
    
};
