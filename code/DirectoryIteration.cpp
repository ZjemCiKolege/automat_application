/*
 * DirectoryIteration.cpp
 *
 *  Created on: 24 Dec 2016
 *      Author: Nico
 */

#include "DirectoryIteration.hpp"
#include <iostream>               // for std::cout

namespace Input
{

DirectoryIteration::DirectoryIteration() :
		location("C:\\Users\\nicov\\Documents\\AutomatApp\\test_data"), file()
{
}

DirectoryIteration::~DirectoryIteration()
{
}

void DirectoryIteration::iterateDirectories()
{
	for (auto it : boost::filesystem::recursive_directory_iterator(location))
	{
		//std::cout << it << std::endl;
		if (boost::filesystem::is_regular_file(it))        // is p a regular file?
		{
			std::cout << it << " size is " << boost::filesystem::file_size(it) << '\n';
			if (boost::filesystem::extension(it) == ".pmd")
			{
				std::cout << "PMD FOUND" << std::endl;
				std::set<std::string> temp = file.parseFile(it);
				matfiles.insert(temp.begin(),temp.end());
			}
		}
		else if (boost::filesystem::is_directory(it))      // is p a directory?
			std::cout << it << "is a directory\n";
		else
			std::cout << it << "exists, but is neither a regular file nor a directory\n";
	}

	std::cout<<"show the set"<<std::endl;
	for(std::string s: matfiles)
	{
		std::cout<<s<<std::endl;
	}
}

} /* namespace Iteration */
