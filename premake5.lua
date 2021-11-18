workspace "Turing"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

-- 多系统支持
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Turing"
	location "Turing"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/SRC/**.h",
		"%{prj.name}/SRC/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"

		defines {
			"TR_PLATFORM_WINDOWS",
			"TR_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TR_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "TR_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "TR_DIST"
		optimize "On"

	-- 目前用不到多线程之后可能会用到
	--filters {"system:windows","configurations:Release"}
		--buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int" .. outputdir .. "/%{prj.name}")
	
	files {
		"%{prj.name}/SRC/**.h",
		"%{prj.name}/SRC/**.cpp"
	}

	includedirs {
		"Turing/vendor/spdlog/include",
		"Turing/SRC"
	}

	links{
		"Turing"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"

		defines {
			"TR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TR_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "TR_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "TR_DIST"
		optimize "On"