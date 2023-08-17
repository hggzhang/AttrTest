#pragma once
#include <memory>

#define SP(Ty) std::shared_ptr<Ty>
#define WP(Ty) std::weak_ptr<Ty>
#define UP(Ty) std::unique_ptr<Ty>

#define MK_SP(Ty, ...) std::make_shared<Ty>(__VA_ARGS__)


