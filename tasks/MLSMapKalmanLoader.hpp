#ifndef ENVIRE_MAPS_MLSMAPKALMANLOADER_TASK_HPP
#define ENVIRE_MAPS_MLSMAPKALMANLOADER_TASK_HPP

#include "envire_maps/MLSMapKalmanLoaderBase.hpp"

namespace envire_maps
{
    class MLSMapKalmanLoader : public MLSMapKalmanLoaderBase
    {
    friend class MLSMapKalmanLoaderBase;

    private:
        maps::grid::MLSMapKalman mMap;

    protected:
        void createMLS(const pcl::PointCloud<pcl::PointXYZ>& pc,
                             maps::grid::Vector2ui gridSize,
                             maps::grid::Vector2d cellSize,
                             maps::grid::Vector3d offset);
        void writeMLS();

    public:
        MLSMapKalmanLoader(std::string const& name = "envire_maps::MLSMapKalmanLoader", TaskCore::TaskState initial_state = Stopped);
        ~MLSMapKalmanLoader();
    };
}

#endif
