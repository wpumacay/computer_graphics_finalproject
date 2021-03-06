
#pragma once

#include <terrain/TTerrain1D.h>
#include <terrain/TTerrain1DPatchVoxels.h>
#include <LFixedCamera3d.h>

using namespace std;

namespace tysoc
{

    class TWorld;

    class TTerrain1DPatched : public TTerrain1D
    {

        private :

        vector< TTerrain1DPatchVoxels* > m_patches;
        vector< engine::LFixedCamera3d* > m_fcameras;

        void _addSection( engine::LVec3 posStart );

        public :

        TTerrain1DPatched( TWorld* pWorld,
                           engine::LVec3 start       = TERRAIN1D_DEFAULT_START,
                           engine::LVec3 direction   = TERRAIN1D_DEFAULT_DIRECTION,
                           engine::LVec3 up          = TERRAIN1D_DEFAULT_UP );
        ~TTerrain1DPatched();

        static string getStaticType() { return string( "patched1d" ); }

        void update( float dt ) override;

        vector< TTerrain1DPatchVoxels* > getPatches() { return m_patches; }

        void setMaterial( const engine::LVec3& ambient,
                          const engine::LVec3& diffuse,
                          const engine::LVec3& specular,
                          float shininess ) override;
    };




}
