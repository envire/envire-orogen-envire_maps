#ifndef ENVIRE_MAPS_MLSMAPSLOPELOADER_TASK_HPP
#define ENVIRE_MAPS_MLSMAPSLOPELOADER_TASK_HPP

#include "envire_maps/MLSMapSlopeLoaderBase.hpp"

namespace envire_maps
{
    class MLSMapSlopeLoader : public MLSMapSlopeLoaderBase
    {
    friend class MLSMapSlopeLoaderBase;

    private:
        maps::grid::MLSMapSloped mMap;

    protected:
        void createMLS(const pcl::PointCloud<pcl::PointXYZ>& pc,
                             maps::grid::Vector2ui gridSize,
                             maps::grid::Vector2d cellSize,
                             maps::grid::Vector3d offset);
        void writeMLS();

    public:
        MLSMapSlopeLoader(std::string const& name = "envire_maps::MLSMapSlopeLoader", TaskCore::TaskState initial_state = Stopped);
        ~MLSMapSlopeLoader();
    };
}

#endif
