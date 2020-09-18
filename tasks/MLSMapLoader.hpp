#ifndef ENVIRE_MAPS_MLSMAPLOADER_TASK_HPP
#define ENVIRE_MAPS_MLSMAPLOADER_TASK_HPP

#include "envire_maps/MLSMapLoaderBase.hpp"

#include <pcl/common/common.h>
#include <maps/grid/Index.hpp>

namespace envire_maps
{
    class MLSMapLoader : public MLSMapLoaderBase
    {
    friend class MLSMapLoaderBase;
    protected:
        bool mMapLoaded;

    protected:
        virtual bool publishMap();

        virtual void createMLS(const pcl::PointCloud<pcl::PointXYZ>& pc,
                               maps::grid::Vector2ui gridSize,
                               maps::grid::Vector2d cellSize,
                               maps::grid::Vector3d offset);
        virtual void writeMLS();

    public:
        MLSMapLoader(std::string const& name = "envire_maps::MLSMapLoader", TaskCore::TaskState initial_state = Stopped);
        virtual ~MLSMapLoader();

        bool configureHook();
    };
}

#endif
