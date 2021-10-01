//
//  ViewFlower.hpp
//  zenGarden
//
//  Created by Yi-Wen LIN on 28/04/2020.
//

#ifndef ViewFlower_hpp
#define ViewFlower_hpp

#include <stdio.h>
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "BatchHelpers.h"
#include "cinder/Perlin.h"

using namespace ci;
using namespace ci::app;
using namespace std;


typedef std::shared_ptr<class ViewFlower> ViewFlowerRef;

class ViewFlower {
public:
    
    struct InstanceData {
        vec3 pos;
        vec3 end;
        vec3 ctrl0;
        vec3 ctrl1;
        vec3 extra;
    };
    
    static ViewFlowerRef create(vec3 mPos) { return std::make_shared<ViewFlower>(mPos); }
    
    ViewFlower(vec3 mPos) {
        _pos = mPos;
        _init();
    }
    
    
    vec3 getPos() {
        return _pos;
    }
    
    
    void update();
    void render();
    
    vec3 getTop();
    float getOpeningOffset();

private :
    int numLeaves;
    int numPetals;
    float timeStart;
    
    vec3 _pos;
    vec3 _top;
    vec3 _topOffset;
    vec3 _ctrl0;
    vec3 _ctrl1;
    
    vector<vec3> _colors;
        
    vec3 getPos(float y, float r);
    
    Perlin perlin;
    
    
    
    gl::GlslProgRef     mShaderLeaves;
    gl::GlslProgRef     mShaderStem;
    gl::GlslProgRef     mShaderFlower;
    
    gl::BatchRef        _bLeaves;
    gl::BatchRef        _bStem;
    gl::BatchRef        _bFlower;
    
    EaseNumberRef       _offset;
    EaseNumberRef       _offsetOpening;
    
    // methods
    void _init();
    
    
};


#endif /* ViewFlower_hpp */
