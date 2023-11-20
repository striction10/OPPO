#include "pch.h"
#include "..\..\ProjectCPP\ProjectCPP\date.cpp"
#include "..\..\ProjectCPP\ProjectCPP\FileInfo.cpp"


TEST(TestInvalidDates)
{
	vector<string> invalidDates{ "", "01.01.01.2000", "10.0.2000", "28.13.2020", "32.10.2023", "01*12*2000", "01 12 2000" };
	for (auto invalidDate : invalidDates)
	{
		EXPECT_THROW(
		{
			Date date;
			date.read(invalidDate);
		},
		std::runtime_error);
	}
}

TEST(TestValidDates)
{
	vector<string> validDates{ "01.01.2000", "09.09.2023", "28.02.2022", "10.12.2019", "01.12.2000" };
	for (auto validDate : validDates)
	{
		Date date;
		date.read(validDate);
		EXPECT_EQ(date.isDateCorrect(), true);
	}
}

TEST(TestInvalidFileNames)
{
	vector<string> invalidFileNames{ "\"test.txt 28.02.2002 5", "te\"st.txt 28.02.2002 35", "*test*.txt 28.02.2002 15", "test.txt\" 28.02.2002 5" };
	for (auto invalidFileName : invalidFileNames)
	{
		EXPECT_THROW(
		{
			FileInfo file_info;
			file_info.readNameFile(invalidFileName);
		},
		std::runtime_error);
	}
}

TEST(TestValidFileNames)
{
	vector<string> validFileNames{ "test  2.txt", "TEST_123.txt", "999super_file_name999.txt" };
	for (auto validFileName : validFileNames)
	{
		FileInfo file_info;
		file_info.readNameFile(validFileName);
		EXPECT_EQ(file_info.get_name_file(), validFileName);
	}
}

TEST(TestInvalidFileSizes)
{
	vector<string> invalidFileSizes{ "-500", "1,24", "255.30" };
	for (auto invalidFileSize : invalidFileSizes)
	{
		EXPECT_THROW(
		{
			FileInfo file_info;
			file_info.readFileSize(invalidFileSize);
		},
		std::runtime_error);
	}
}

TEST(ValidFileSizes)
{
	vector<string> validFileSizes{ "500", "999", "10000"};
	for (auto validFileSize : validFileSizes)
	{
		FileInfo file_info;
		file_info.readFileSize(validFileSize);
		EXPECT_EQ(file_info.get_file_size(), stoi(validFileSize));
	}
}

TEST(PrintLayoutFileInfo)
{
	FileInfo file_info;
	file_info.readNameFile("Test.txt");
	file_info.readDate("10.11.2023");
	file_info.readFileSize("500");

	std::ostringstream out;
	file_info.printLayoutFileInfo(out);
	EXPECT_EQ(out.str(), "\nFile name: Test.txt\nDate: 2023.11.10\nWeight: 500\n");
}
