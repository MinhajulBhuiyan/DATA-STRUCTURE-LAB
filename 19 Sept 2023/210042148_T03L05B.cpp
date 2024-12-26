#include <iostream>
#include <cmath>

// Function to calculate the area of a triangle using Heron's formula
double calculateTriangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to perform binary search to find XL
double findXL(double XY, double XZ, double YZ, double areaRatio) {
    double low = 0, high = XY;
    double XL = 0;

    while (high - low > 1e-9) {  // Precision error threshold
        XL = (low + high) / 2.0;
        double XE = XY - XL;

        // Calculate the areas of triangles XLM and LMZY
        double areaXLM = calculateTriangleArea(XL, XE, XZ);
        double areaLMZY = calculateTriangleArea(XE, YZ, XZ);

        // Calculate the current area ratio
        double currentAreaRatio = areaXLM / areaLMZY;

        // Adjust the bounds based on the comparison of area ratios
        if (currentAreaRatio < areaRatio) {
            high = XL;
        } else {
            low = XL;
        }
    }

    return XL;
}

int main() {
    int T;
    std::cin >> T;

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        double XY, XZ, YZ, areaRatio;
        std::cin >> XY >> XZ >> YZ >> areaRatio;

        double XL = findXL(XY, XZ, YZ, areaRatio);

        std::cout << "Case " << caseNum << ": " << XL << std::endl;
    }

    return 0;
}