#pragma once
//////////////////////////////////////////////////////////////////////
// GPU 2D antialiased line drawing
//////////////////////////////////////////////////////////////////////

#include <TFE_System/types.h>

struct Camera3d
{
	Vec3f pos;
	Mat3  viewMtx;
	Mat4  projMtx;

	f32 yaw;
	f32 pitch;
};
