#pragma once
#include <array>

namespace Geometry {

    class Matrix {
    public:
        Matrix(); 
        Matrix(const std::array<std::array<float, 4>, 4>& values); 

        static Matrix Identity();  
        static Matrix Translation(float tx, float ty, float tz);  
        static Matrix Scaling(float sx, float sy, float sz);  
        static Matrix RotationX(float angle);  
        static Matrix RotationY(float angle);  
        static Matrix RotationZ(float angle);  

        Matrix operator*(const Matrix& other) const;  // Matrix multiplication
        std::array<float, 4> operator*(const std::array<float, 4>& vector) const; // Matrix-vector multiplication

        const std::array<std::array<float, 4>, 4>& Values() const;

    private:
        std::array<std::array<float, 4>, 4> values;
    };

}
