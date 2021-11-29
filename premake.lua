workspace "Lesson 4"
	location ".\\build\\"

	targetdir "%{wks.location}\\bin\\%{cfg.buildcfg}\\"
	objdir "%{wks.location}\\obj\\%{cfg.buildcfg}\\%{prj.name}\\"
	buildlog "%{wks.location}\\obj\\%{cfg.buildcfg}\\%{prj.name}.log"

	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	systemversion "latest"
	characterset "ascii"
	architecture "x86"
	warnings "extra"

	buildoptions {
		"/std:c++17",
	}

	includedirs {
		".\\src\\",
	}

	platforms {
		"x86",
	}

	configurations {
		"Release",
		"Debug",
	}

	configuration "Release"
		defines "NDEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	configuration "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	project "Lesson 4"
		targetname "lesson_4"
		language "c++"
		kind "consoleapp"
		warnings "off"

		pchheader "stdafx.hpp"
		pchsource "src/stdafx.cpp"
		forceincludes "stdafx.hpp"
		
		files {
			".\\Lesson_4\\**",
		}

		includedirs {
			".\\Lesson_4\\",
		}