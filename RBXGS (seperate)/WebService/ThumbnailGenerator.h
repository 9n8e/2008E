#pragma once

#include <string>

#include "G3D/BinaryOutput.h"

class ThumbnailGenerator {
public: 
    ThumbnailGenerator(const ThumbnailGenerator&);
    ThumbnailGenerator();
    virtual ~ThumbnailGenerator();
    std::string click(std::string, int, int, bool);
    std::string clickTexture(std::string, std::string, int, int);
    void doClick(std::string, int, int, bool, G3D::BinaryOutput*);
    ThumbnailGenerator& operator=(const ThumbnailGenerator&);
};