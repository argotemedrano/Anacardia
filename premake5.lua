workspace "Anacardia"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["imgui"] = "vendor/imgui"
IncludeDir["glm"] = "vendor/glm/glm"
IncludeDir["spdlog"] = "vendor/spdlog/include"

include "vendor/GLFW"
include "vendor/Glad"
include "vendor/imgui"

project "Anacardia"
	location "Anacardia"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Anacardia/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Platform/Windows",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"imgui",
		"Glad"
	}

	defines
	{
		"GLFW_INCLUDE_NONE"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ANACARDIA_PLATFORM_WINDOWS",
			"ACAR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ACAR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ACAR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ACAR_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"vendor/spdlog/include",
		"Anacardia/src",
		"Platform/Windows"
	}

	links
	{
		"Anacardia"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ANACARDIA_PLATFORM_WINDOWS"
		}

		
	filter "configurations:Debug"
		defines "ACAR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ACAR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ACAR_DIST"
		optimize "On"