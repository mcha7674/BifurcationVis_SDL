-- BifurcationSDL2 solution
workspace "BifurcationSDL2"
    startproject "BifurcationSDL2" -- set the starting project
    architecture "x64"
    startproject "BifurcationSDL2"

    configurations -- set to debug and release for All Configurations
    {
        "Debug",
        "Release"
    }

    flags -- use multithreading to compile project
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "BifurcationSDL2"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files -- add the following files to the project
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs -- Additional Includes (relative to the premake file)
	{
		"vendor/SDL2-2.26.3/include",
	}

    libdirs
    {
        "vendor/SDL2-2.26.3/lib/x64/"
    }
	links -- reference Libs
	{
		"SDL2",
        "SDL2main"
	}
    

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLCORE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
        optimize "on"

-- includeexternal will reference the opengl-core lua file but not regenerate it. It was already 
-- includeexternal "OpenGL-Core"
-- include "AlgoVisCPP"