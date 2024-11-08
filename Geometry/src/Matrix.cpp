#include "Matrix.h"
#include <cmath>

namespace Geometry {

        Matrix::Matrix() : values(Identity().values) {}

        Matrix::Matrix(const std::array<std::array<float, 4>, 4>& initValues)
            : values(initValues) {}

        Matrix Matrix::Identity() {
            std::array<std::array<float, 4>, 4> identityValues = { {
                {{1.0f, 0.0f, 0.0f, 0.0f}},
                {{0.0f, 1.0f, 0.0f, 0.0f}},
                {{0.0f, 0.0f, 1.0f, 0.0f}},
                {{0.0f, 0.0f, 0.0f, 1.0f}}
            } };
            return Matrix(identityValues);  
        }

    Matrix Matrix::Translation(float tx, float ty, float tz) {
        return Matrix{ {
            {1.0f, 0.0f, 0.0f, tx},
            {0.0f, 1.0f, 0.0f, ty},
            {0.0f, 0.0f, 1.0f, tz},
            {0.0f, 0.0f, 0.0f, 1.0f}
        } };
    }

    Matrix Matrix::Scaling(float sx, float sy, float sz) {
        return Matrix{ {
            {sx, 0.0f, 0.0f, 0.0f},
            {0.0f, sy, 0.0f, 0.0f},
            {0.0f, 0.0f, sz, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        } };
    }

    Matrix Matrix::RotationX(float angle) {
        float c = cos(angle);
        float s = sin(angle);
        return Matrix{ {
            {1.0f, 0.0f, 0.0f, 0.0f},
            {0.0f, c, -s, 0.0f},
            {0.0f, s, c, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        } };
    }

    Matrix Matrix::RotationY(float angle) {
        float c = cos(angle);
        float s = sin(angle);
        return Matrix{ {
            {c, 0.0f, s, 0.0f},
            {0.0f, 1.0f, 0.0f, 0.0f},
            {-s, 0.0f, c, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        } };
    }

    Matrix Matrix::RotationZ(float angle) {
        float c = cos(angle);
        float s = sin(angle);
        return Matrix{ {
            {c, -s, 0.0f, 0.0f},
            {s, c, 0.0f, 0.0f},
            {0.0f, 0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        } };
    }

    Matrix Matrix::operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.values[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    result.values[i][j] += values[i][k] * other.values[k][j];
                }
            }
        }
        return result;
    }

    std::array<float, 4> Matrix::operator*(const std::array<float, 4>& vector) const {
        std::array<float, 4> result{ 0.0f, 0.0f, 0.0f, 0.0f };
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result[i] += values[i][j] * vector[j];
            }
        }
        return result;
    }

    const std::array<std::array<float, 4>, 4>& Matrix::Values() const {
        return values;
    }

}
