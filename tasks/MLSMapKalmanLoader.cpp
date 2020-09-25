#include "MLSMapKalmanLoader.hpp"

using namespace envire_maps;

MLSMapKalmanLoader::MLSMapKalmanLoader(std::string const& name, TaskCore::TaskState initial_state)
    : MLSMapKalmanLoaderBase(name, initial_state)
{
}

MLSMapKalmanLoader::~MLSMapKalmanLoader()
{
}

void MLSMapKalmanLoader::createMLS(const pcl::PointCloud<pcl::PointXYZ>& pc,
                                  maps::grid::Vector2ui gridSize,
                                  maps::grid::Vector2d cellSize,
                                  maps::grid::Vector3d offset)
{
    mMap.frame_id = _map_frame;
    mMap.time = base::Time::now();
    mMap.data = maps::grid::MLSMapKalman(gridSize, cellSize, _mls_config);
    mMap.data.translate(offset);
    mMap.data.mergePointCloud(pc, base::Transform3d::Identity());
}

void MLSMapKalmanLoader::writeMLS()
{
    _map.write(mMap);
}
