#!/usr/bin/env bash

cppFilenames=$(find ./src -type f -name "*.cpp")
assembly="Vulkan_Playground"
compilerFlags="-std=c++17 -O2"
includeFlags="-I./src"
linkerFlags="-lglfw -lvulkan -ldl -lpthread -lX11 -lXrandr"
defines=""

function buildShaders()
{
	echo "Building Shaders"

	./src/shaders/compile_shaders.sh
}

function buildAssembly()
{
	echo "Building $assembly"

	g++ $cppFilenames $compilerFlags $defines $includeFlags $linkerFlags -o $assembly
}

function runAssembly()
{
	echo "Running $assembly"

	./"$assembly"
}

buildShaders && buildAssembly && runAssembly
