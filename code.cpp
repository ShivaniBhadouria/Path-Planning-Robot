#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Grid {
public:
    static std::vector<std::vector<std::array<uint8_t, 3>>> grid;
    static int distanceValue, totalDistance, gridWidth, gridHeight, amountOfObstacles;
    static float obstaclePercent;
    static int startNodeX, startNodeY, endNodeX, endNodeY;
    static std::vector<std::pair<int, int>> listOfPathCords;
    
    static const std::array<uint8_t, 3> emptyNode;
    static const std::array<uint8_t, 3> obstacleNode;
    static const std::array<uint8_t, 3> startNode;
    static const std::array<uint8_t, 3> endNode;
    static const std::array<uint8_t, 3> path;

    static bool isNodeEmpty(const std::array<uint8_t, 3>& arrayValues) {
        return arrayValues == emptyNode;
    }

    static bool isNodeObstacle(const std::array<uint8_t, 3>& arrayValues) {
        return arrayValues == obstacleNode;
    }

    static bool isNodeStart(const std::array<uint8_t, 3>& arrayValues) {
        return arrayValues == startNode;
    }

    static bool isNodeEnd(const std::array<uint8_t, 3>& arrayValues) {
        return arrayValues == endNode;
    }

    static bool isNodePath(const std::array<uint8_t, 3>& arrayValues) {
        return arrayValues == path;
    }

    static int randomGridValueX() {
        return rand() % gridWidth;
    }

    static int randomGridValueY() {
        return rand() % gridHeight;
    }

    static void calculateAmountOfObstacles() {
        amountOfObstacles = static_cast<int>(round(gridHeight * gridWidth * obstaclePercent));
    }

    static void calculateObstacles() {
        while (amountOfObstacles != 0) {
            int obsX = randomGridValueX();
            int obsY = randomGridValueY();

            if (isNodeEmpty(grid[obsX][obsY])) {
                grid[obsX][obsY] = obstacleNode;
                amountOfObstacles--;
            }
        }
    }

    static void calculateStartNode() {
        startNodeX = randomGridValueX();
        startNodeY = randomGridValueY();
        grid[startNodeX][startNodeY] = startNode;
    }

    static void calculateEndNode() {
        endNodeY = randomGridValueY();
        while (true) {
            endNodeX = randomGridValueX();
            if (startNodeX != endNodeX) break;
        }
        grid[endNodeX][endNodeY] = endNode;
    }

    static std::vector<std::vector<std::array<uint8_t, 3>>> gridComputation(int gw, int gh, float obstaclePercent) {
        grid = std::vector<std::vector<std::array<uint8_t, 3>>>(gw, std::vector<std::array<uint8_t, 3>>(gh, {255, 255, 255}));
        gridWidth = gw;
        gridHeight = gh;
        Grid::obstaclePercent = obstaclePercent;

        calculateStartNode();
        calculateEndNode();
        calculateAmountOfObstacles();
        calculateObstacles();
        return grid;
    }
};

// Static member initialization
std::vector<std::vector<std::array<uint8_t, 3>>> Grid::grid;
int Grid::distanceValue = 0;
int Grid::totalDistance = 0;
int Grid::gridWidth = 0;
int Grid::gridHeight = 0;
int Grid::amountOfObstacles = 0;
float Grid::obstaclePercent = 0.0;
int Grid::startNodeX = 0;
int Grid::startNodeY = 0;
int Grid::endNodeX = 0;
int Grid::endNodeY = 0;
std::vector<std::pair<int, int>> Grid::listOfPathCords;
const std::array<uint8_t, 3> Grid::emptyNode = {255, 255, 255};
const std::array<uint8_t, 3> Grid::obstacleNode = {0, 0, 0};
const std::array<uint8_t, 3> Grid::startNode = {0, 100, 0};
const std::array<uint8_t, 3> Grid::endNode = {214, 71, 49};
const std::array<uint8_t, 3> Grid::path = {0, 167, 189};

// Additional classes for GridSlowMode and GridShortestPath would follow a similar structure, with method implementations adjusted for C++ syntax and conventions.

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator
    Grid::gridComputation(300, 300, 0.1f); // Example usage
    return 0;
}
