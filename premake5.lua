workspace "GameEngineTest1"
    architecture "x64"
    startproject "Sandbox"

    configurations
	{
		"Debug",
		"Release",
		"Dist"
    }
    
    flags
	{
		"MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["spdlog"] = "%{wks.location}/BrickEngine/vendor/spdlog/include"
    
project "BrickEngine"
    location "BrickEngine"
    kind "StaticLib"
	language "C++"
	cppdialect "C++17"
    staticruntime "on"
    
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "brickpch.hpp"
    pchsource "%{prj.name}/src/brickpch.cpp"
    
    files
	{
		"%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
	{
		"%{prj.name}/src",
        "%{IncludeDir.spdlog}"
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
    }

    filter "system:windows"
		systemversion "latest"

		defines
		{
            "BRICKENGINE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BRICKENGINE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BRICKENGINE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BRICKENGINE_DIST"
		runtime "Release"
        optimize "on"
        
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
    staticruntime "on"
    
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
	{
		"%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
	{
		"%{prj.name}/src",
		"%{wks.location}/BrickEngine/src",
        "%{IncludeDir.spdlog}"
    }

    links
    {
        "BrickEngine"
    }

    filter "system:windows"
		systemversion "latest"

		defines
		{
            "BRICKENGINE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BRICKENGINE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BRICKENGINE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BRICKENGINE_DIST"
		runtime "Release"
		optimize "on"