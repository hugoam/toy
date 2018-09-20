//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <visu/Ogre/OgreViewport.h>

using namespace mud; namespace toy
{
	OgreViewport::OgreViewport(Widget* parent, void* identity, Scene& scene)
		: Viewer(parent, identity, scene)
	{
		// camera->camera()->addCameraObserver(this);
	}

	/*void OgreViewport::addFocusObject(VisuEntity* object)
	{
		mFocusObjects.push_back(object);
		object->addFocusObserver(this);
	}

	void OgreViewport::removeFocusObject(VisuEntity* object)
	{
		vector_remove(mFocusObjects, object);
		object->removeFocusObserver(this);
	}*/

	/*void OgreViewport::focusUpdate(VisuEntity* target, const vec3& position)
	{
		// For each focused entity that moves
		// We cast a ray between the camera and the entity position

		VisuEntity* blocking = checkBlocking(position);

		VisuEntity* old = mBlockingFocus[target];
		if(old != NULL && old != blocking)
			old->disableObstructing();
			// @crash : we can't operate on an OgreEntity we stored before if we can't be sure it's still valid

		if(blocking && target != blocking) // @kludge maybe ?
		{
			blocking->enableObstructing();
			mBlockingFocus[target] = blocking;
		}
	}

	VisuEntity* OgreViewport::checkBlocking(const vec3& position)
	{
		static Ogre::Ray ray;

		Ogre::vec3 origin = mCamera->ogreCamera()->getPosition();
		Ogre::vec3 target(position[0], position[1], position[2]);
		Ogre::vec3 normal = target - origin;
 
		ray.setOrigin(origin);
		ray.setDirection(normal);

		Ogre::vec3 result;
		Ogre::MovableObject* object;

		uint32_t queryMask = SHADEABLE_OGRE_MASK;

		float f = 0.f;
		if (mCollisionTools->raycast(ray, result, object, f, queryMask))
		{
			const Ogre::Any& any = object->getUserObjectBindings().getUserAny();
			if (!any.isEmpty())
				return Ogre::any_cast<VisuEntity*> (any);
		}

		return NULL;
	}*/

	/*void OgreViewport::cameraUpdated(const vec3& position, const quat& rotation, const vec3& target, float nearClipDist, float farClipDist)
	{
		//for(auto it = mFocusObjects.begin(); it != mFocusObjects.end(); ++it)
		//	focusUpdate((*it), (*it)->m_spatial->position());
	}*/
}
