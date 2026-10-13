#pragma once
#include <cstddef>
#include <stack>
#include <stdexcept>
#include <vector>
#include <memory>

#include "PoolHandle.h"

template<typename T>
class ObjectPool
{
	friend class PoolHandle<T>;
public:

	explicit ObjectPool(size_t capacity)
	{
		objects_.reserve(capacity);
		for (size_t i = 0; i < capacity; ++i)
		{
			objects_.emplace_back(std::make_unique<T>());
			free_.push(objects_.back().get());
		}
	}

	PoolHandle<T> Acquire()
	{
		if (free_.empty()) throw std::runtime_error("ObjectPool is empty");
		T* obj = free_.top();
		free_.pop();
		return PoolHandle<T>(obj, this);

	}

private:

	void Release(T* obj) {
		free_.push(obj);
	}

	//	Ç±Ç±Ç™èäóLé“
	std::vector<std::unique_ptr<T>> objects_;
	std::stack<T*> free_;
};

template<typename T>
PoolHandle<T>::~PoolHandle()
{
	if (obj_ != nullptr && pool_ != nullptr) {
		pool_->Release(obj_);
	}
}