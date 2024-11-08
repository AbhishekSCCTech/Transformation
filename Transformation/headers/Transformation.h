#pragma once
#pragma once
#include "Matrix.h"
#include "Triangulation.h"

namespace Geometry {

    class Transformation {
    public:
        static void ApplyTranslation(Triangulation& triangulation, float tx, float ty, float tz);
        static void ApplyScaling(Triangulation& triangulation, float sx, float sy, float sz);
        static void ApplyRotation(Triangulation& triangulation, float angle, char axis);

    private:
        static void TransformTriangulation(Triangulation& triangulation, const Matrix& transform);
    };

}
