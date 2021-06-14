//
// Created by Sun,Minqi on 2021/6/11.
//

#pragma once
#include "../util.h"
namespace proxy {
    struct Image{
        virtual void draw() = 0;
    };
    struct Bitmap : Image {
        explicit Bitmap(std::string filename): _filename(std::move(filename)) {
            std::cout << "Loading image from " << filename << std::endl;
        }

        void draw() override {
            std::cout << "Drawing image " << _filename << std::endl;
        }

    private:
        std::string _filename;
    };
    struct LazyBitmap : Image {
        explicit LazyBitmap(std::string filename): _filename(std::move(filename)) {}
        void draw() override {
            std::cout << "Begin Lazy Load image" << std::endl;
            _bitmap = std::make_unique<Bitmap>(_filename);
            _bitmap->draw();
        }
    private:
        std::unique_ptr<Bitmap> _bitmap;
        std::string _filename;
    };
}