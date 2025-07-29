#pragma once

namespace HexOpt
{
    int optimizeMesh( const std::string& trifile,
                      const std::string& hexfile,
                      const std::string& ftrfile,
                      const std::string& outputfile );

    struct HexMeshInfo
    {
        const int pNum; // number of points
        const int eNum; // number of elements
        std::vector<std::vector<int>> hex; // hexes, each defined by 8 vertex indices
        std::vector<double> x; // point coordinates, in 3D
        const std::vector<std::vector<int>> adjPts; // adjacency list for each point
    };
    struct FeatureInfo
    {
        FeatureInfo( const int pnum )
            : edgeFtrX(),
              hexPtType( pnum, std::vector<int>( 1, 0 ) )
        {}
        FeatureInfo( const std::vector<std::vector<double>>& edgeFtrX,
                     const std::vector<std::vector<int>>& hexPtType )
            : edgeFtrX( edgeFtrX ),
              hexPtType( hexPtType )
        {}
        const std::vector<std::vector<double>> edgeFtrX;
        const std::vector<std::vector<int>> hexPtType;
    };
    struct TriMeshInfo
    {
        const int triENum; // number of triangles
        std::vector<std::vector<int>> tri; // triangles, each defined by 3 vertex indices
        std::vector<std::vector<double>> triX; // triangle vertex coordinates, in 3D
        std::vector<std::vector<std::vector<double>>> triEdgeX; // edge coordinates for each triangle
    };

    int optimizeMesh( HexMeshInfo& hexMeshInfo,
                      const FeatureInfo& featureInfo,
                      const TriMeshInfo& triMeshInfo,
                      const std::string& outputHexFileName, const bool move_bdry_points = false );
}