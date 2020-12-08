#pragma once
#include "CaloCell.hh"

class CaloGrid {
   public:
    CaloGrid(int NX = 5, int NY = 5) : nx(NX), ny(NY) {
        // ny=NY;
        // nx=NX;
        init(nx, ny);
    };

    CaloGrid(const CaloGrid& other) : nx(other.nx), ny(other.ny) {
        init(other.nx, other.ny);
        for (int i = 0; i < other.nx; i++) {
            for (int j = 0; j < other.ny; j++) {
                grid[i][j] = other.grid[i][j];
            }
        }
    };

    ~CaloGrid() {
        for (int i = 0; i < nx; i++) {
            delete[] grid[i];
        };
        delete[] grid;
    };

    CaloCell* cell(int x, int y) {
        if ((x <= nx) && (y <= ny)) {
            return &(grid[x][y]);
        } else {
            return nullptr;
        }
    };

    const CaloCell* cell(int x, int y) const {
        if ((x <= nx) && (y <= ny)) {
            return &(grid[x][y]);
        } else {
            return nullptr;
        }
    };

   private:
    int nx, ny;
    CaloCell** grid;

    void init(int nx, int ny) {
        grid = new CaloCell*[nx];
        for (int i = 0; i < nx; i++) {
            grid[i] = new CaloCell[ny];
        }
    };
};
