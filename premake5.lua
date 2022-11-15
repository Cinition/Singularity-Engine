project "Singularity"

    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}"
    staticruntime "off"

    targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../Bin-Int/" .. outputdir .. "/%{prj.name}")

    files {
        "Src/**.h",
        "Src/**.cpp",
    }

    includedirs {
        "Src",
        "Vendor/GLFW/include",
        "Vendor/imgui",
        "Vendor/GLM",
        "%{VULKAN_ENV}/Include",
    }

    include "Vendor/vendor.lua"

    links {
        "GLFW",
        "ImGui",
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

    filter "configurations:Publish"
        defines { "WL_DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"

project "Vulkan"

    kind "StaticLib"
    language "C"
    staticruntime "off"

    files { 
        "%{VULKAN_ENV}/Include/**.h",
        "%{VULKAN_ENV}/Include/**.cpp",
    }
