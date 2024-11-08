#include "Transformation.h"
#include "Triangulation.h"
#include "Point.h"


namespace Geometry {

    void Transformation::ApplyTranslation(Triangulation& triangulation, float tx, float ty, float tz) {
        Matrix translationMatrix = Matrix::Translation(tx, ty, tz);
        TransformTriangulation(triangulation, translationMatrix);
    }

    void Transformation::ApplyScaling(Triangulation& triangulation, float sx, float sy, float sz) {
        Matrix scalingMatrix = Matrix::Scaling(sx, sy, sz);
        TransformTriangulation(triangulation, scalingMatrix);
    }

    void Transformation::ApplyRotation(Triangulation& triangulation, float angle, char axis) {
        Matrix rotationMatrix;
        switch (axis) {
        case 'x': rotationMatrix = Matrix::RotationX(angle); break;
        case 'y': rotationMatrix = Matrix::RotationY(angle); break;
        case 'z': rotationMatrix = Matrix::RotationZ(angle); break;
        default: return; // Invalid axis
        }
        TransformTriangulation(triangulation, rotationMatrix);
    }

    void Transformation::TransformTriangulation(Triangulation& triangulation, const Matrix& transform) {
        // Apply transformation to each point in the triangulation
        for (auto& triangle : triangulation.Triangles) {
            std::vector<Point> points = triangle.Points();
            for (auto& point : points) {
                std::array<float, 4> pointVec = { point.X(), point.Y(), point.Z(), 1.0f };
                std::array<float, 4> transformedVec = transform * pointVec;
                point = Point(static_cast<int>(transformedVec[0]), static_cast<int>(transformedVec[1]), static_cast<int>(transformedVec[2]));
            }
        }
    }

}
