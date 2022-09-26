#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "CovidCollection.h"
#include "CovidCollection.h"

void printbar(std::ostream &out = std::cout)
{
	out << std::setw(89) << std::setfill('-') << '\n'
		<< std::setfill(' ');
}

void printHeader(const char *title, std::ostream &out = std::cout)
{
	printbar(out);
	out << "| " << std::left << std::setw(85) << title << std::right << "|\n";
	printbar(out);
}

int main(int argc, char **argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::CovidCollection theCollection(argv[1]);

	printHeader("The original collection");
	theCollection.display(std::cout);
	printbar();

	printHeader("The collection sorted by country");
	theCollection.sort("country");
	theCollection.display(std::cout);
	printbar();

	printHeader("The collection sorted by variants");
	theCollection.sort("variant");
	theCollection.display(std::cout);
	printbar();

	printHeader("The collection sorted by total cases");
	theCollection.sort("cases");
	theCollection.display(std::cout);
	printbar();

	printHeader("The collection sorted by deaths");
	theCollection.sort("deaths");
	theCollection.display(std::cout);
	printbar();

	printHeader("The collection with fixed covid variants names");
	theCollection.cleanList();
	theCollection.display(std::cout);
	printbar();

	{
		// looking for "Omicron" in the collection
		if (theCollection.inCollection("Omicron"))
			std::cout << "There are covid variants of \"Omicron\" in collection.\n";
		else
			std::cout << "There are no covid variants \"Omicron\" in collection.\n";
	}

	{
		// look for Gamma variants; the death for Gamma variants were underreported by 50 deaths
		if (theCollection.inCollection("Gamma"))
		{
			printHeader("Covid Variant of \"Gamma\"");
			auto gamma = theCollection.getListForVariant("Gamma");
			for (auto &covid : gamma)
			{
				std::cout << covid << "\n";
				covid.m_deaths += 50;
			}
			printbar();
		}
	}
}