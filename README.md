# Avid Insight Library (ail) for C++

 * Author:  Peter R. Bloomfield
 * Web:     avidinsight.uk
 * License: MIT

## WARNING

This is still extremely early in development. I don't recommend using it for anything whatsoever as I'm still making a lot of changes in design and planning as I go along.


## Summary

This library is a collection of tools and utilities for various purposes. It's partly geared towards maths, particularly as needed in games programming, but also has (or will have) other more general features.


## Repository structure

 * *inc/ail* - C++ header files (.h) for the library.
 * *src* - C++ source code files (.cpp) for the library.
 * *test* - header and source code files for the test project which checks library functionality.
 * *vs2015* - Visual Studio 2015 solution/project files for building the library and the test project.

 
## Testing

One of my aims is to make the library as robust as possible. With that in mind, the **test** sub-project was created. It uses the [Catch][1] framework to validate the results of nearly every class and function. The aim is that any new functionality which gets added on a branch should demonstrate a good range of successful tests before it can be committed to the master.
 

## Dependencies and requirements

The library makes extensive uses of features from the C++11 standard, so a reasonably up-to-date compiler is required.

Currently the only external dependency is the [Catch][1] framework, used to implement test cases. It's not required for the library itself, but all additions to the library must have suitable test cases implemented.


## Usage

The code in this library is distributed freely under the MIT License. This means you can use and modify the code for pretty much anything you want (at your own risk), but you cannot change the license terms or remove the copyright notice. As a courtesy, please also acknowledge this library and/or its author(s) in your credits or other list of contributors to your project.


[1]: https://github.com/philsquared/Catch