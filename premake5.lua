VULKAN_ENV = os.getenv("VULKAN_SDK")

project( "Singularity ")

    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    files { "src/**.h", "src/**.cpp" }

    includedirs {
        "src",
        "Vendors/GLFW/include",
        "Vendors/GLM",
        "%{VULKAN_ENV}/Include",
    }

    include "Vendor/vendor.lua"

    links {
        "GLFW",
        "%{VULKAN_ENV}/Lib/vulkan-1.lib",
    }

    filter "system:windows"
        systemversion "latest"
        defines { "WL_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines { "WL_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "WL_RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "WL_DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"