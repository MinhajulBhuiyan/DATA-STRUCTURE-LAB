#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

double calculateArea(double x, double h) {
    return 0.5 * x * h;
}

double findXL(double XY, double XZ, double YZ, double areaRatio) {
    priority_queue<double> pq;
    double left = 0.0;
    double right = XY; // Maximum possible value of XL

    // Add initial XL values to the priority queue
    pq.push(left);
    pq.push(right);

    while (!pq.empty()) {
        double XL = pq.top();
        pq.pop();

        double LM = XY - XL; // Length of LM

        // Calculate the areas of triangles
        double areaXLM = calculateArea(XL, XZ);
        double areaLMZY = calculateArea(LM, YZ);

        // Calculate the current area ratio
        double currentRatio = areaXLM / areaLMZY;

        if (abs(currentRatio - areaRatio) < 1e-7) {
            // Found XL that matches the area ratio
            return XL;
        }

        if (currentRatio < areaRatio) {
            // XL is too large, add a smaller XL to the priority queue
            right = XL;
            pq.push((left + right) / 2);
        } else {
            // XL is too small, add a larger XL to the priority queue
            left = XL;
            pq.push((left + right) / 2);
        }
    }

    return -1; // Not found
}

int main() {
    int T;
    cin >> T;

    for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
        double XY, XZ, YZ, areaRatio;
        cin >> XY >> XZ >> YZ >> areaRatio;

        double XL = findXL(XY, XZ, YZ, areaRatio);

        cout << fixed << setprecision(7);
        cout << "Case " << caseNumber << ": " << XL << endl;
    }

    return 0;
}
