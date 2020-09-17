#include "MLSMapSlopeLoader.hpp"

using namespace envire_maps;

MLSMapSlopeLoader::MLSMapSlopeLoader(std::string const& name, TaskCore::TaskState initial_state)
    : MLSMapSlopeLoaderBase(name, initial_state)
{
}

MLSMapSlopeLoader::~MLSMapSlopeLoader()
{
}

void MLSMapSlopeLoader::createMLS(const pcl::PointCloud<pcl::PointXYZ>& pc,
                                  maps::grid::Vector2ui gridSize,
                                  maps::grid::Vector2d cellSize,
                                  maps::grid::Vector3d offset)
{
    mMap.frame_id = _map_frame;
    mMap.time = base::Time::now();
    mMap.data = maps::grid::MLSMapSloped(gridSize, cellSize, _mls_config);
    mMap.data.translate(offset);
    mMap.data.mergePointCloud(pc, base::Transform3d::Identity());
}

void MLSMapSlopeLoader::writeMLS()
{
    _map.write(mMap);
}
