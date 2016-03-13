#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <memory>
#include <assert.h>

namespace Textures
{
	enum ID { Projectile };
}

namespace Fonts
{
	enum ID { NuSM};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void				load		(Identifier id, const std::string& filename);
	Resource&			get		(Identifier id);
	const Resource&		get		(Identifier id) const;
private:
	std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;

};

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	if(!resource->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	auto inserted =  mResourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourceMap.find(id);
	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	return *found->second;
}

#endif // RESOURCEHOLDER_HPP
