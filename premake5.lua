workspace "Singularity"
    architecture "x86_64"
    startproject "Singularity"

	configurations {
		"Debug",
		"Release"
	}

    group "Dependencies"
        include "Dependencies/glfw"
    group ""

    project "Singularity"

        kind "StaticLib"
        language "C++"
        cppdialect "C++17"
        staticruntime "off"

        targetdir ( "bin/" .. outputdir .. "/%{prj.name}" )
        objdir    ( "obj/" .. outputdir .. "/%{prj.name}" )

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"
            defines { "DEBUG" }

        filter "configurations:Release"
            runtime "Release"
            optimize "speed"
            symbols "off"
            defines { "RELEASE" }

        files {
            "Src/**.h",
            "Src/**.cpp"
        }


        
