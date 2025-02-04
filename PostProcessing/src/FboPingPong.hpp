//
//  FboPingPong.hpp
//  PostProcessing
//
//  Created by Yi-Wen LIN on 25/05/2020.
//

#ifndef FboPingPong_hpp
#define FboPingPong_hpp

#include <stdio.h>
#include "cinder/gl/Fbo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class FboPingPong {
public :
    FboPingPong(int mWidth, int mHeight) {
        _width = mWidth;
        _height = mHeight;
        _init();
    }
    
    int getWidth() {
        return _width;
    }
    
    int getHeight() {
        return _height;
    }
    
    gl::FboRef read() {
        return _fbos.at(0);
    }
    
    gl::FboRef write() {
        return _fbos.at(1);
    }
    
    void swap() {
        reverse(_fbos.begin(), _fbos.end());
    }
    
    
private:
    int _width;
    int _height;
    int _index = 0;
    
    vector<gl::FboRef> _fbos;
    
    void _init() {
        gl::Fbo::Format fboFormatA;
        gl::FboRef fboA = gl::Fbo::create( _width, _height, fboFormatA.colorTexture() );
        gl::Fbo::Format fboFormatB;
        gl::FboRef fboB = gl::Fbo::create( _width, _height, fboFormatB.colorTexture() );
        
        _fbos.push_back(fboA);
        _fbos.push_back(fboB);
    }
};

#endif /* FboPingPong_hpp */
