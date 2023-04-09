#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFun.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();

    // SEt kích thước cho ảnh
    void SetRect(const int& x, const int& y) {rect_.x = x; rect_.y = y;}

    // Lấy ra kích thước ảnh
    SDL_Rect GetRect() const {return rect_;}

    // Lấy ra biến lưu giữ ảnh
    SDL_Texture* GetObject() const {return p_object_;}  //const : đảm bảo tính chặt chẽ

    virtual bool LoadImg(std::string path, SDL_Renderer* screen);

    // Render hình ảnh
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);

    void Free();


protected:
    SDL_Texture* p_object_; // biến lưu giữ hình ảnh
    SDL_Rect rect_;         // biến lưu giữ kích thước ảnh
};
#endif // BASE_OBJECT_H_
