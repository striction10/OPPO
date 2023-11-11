#include "pch.h"
#include "..\..\ProjectCPP\ProjectCPP\date.cpp"
#include "..\..\ProjectCPP\ProjectCPP\FileInfo.cpp"

TEST(TestEmptyDate)
{
	EXPECT_THROW(
	{
		Date date;
		date.read(istringstream(""));
	},
	std::runtime_error);
}

TEST(TestInvalidDate1)
{
	EXPECT_THROW(
	{
		Date date;
		date.read(istringstream("01.01.01.2000"));
	},
	std::runtime_error);
}

TEST(TestInvalidDate2)
{
	EXPECT_THROW(
	{
		Date date;
		date.read(istringstream("10.0.2000"));
	},
	std::runtime_error);
}

TEST(TestInvalidDate3)
{
	EXPECT_THROW(
	{
		Date date;
		date.read(istringstream("28.13.2020"));
	},
	std::runtime_error);
}

TEST(TestInvalidDate4)
{
	EXPECT_THROW(
	{
		Date date;
		date.read(istringstream("32.10.2023"));
	},
	std::runtime_error);
}

TEST(TestInvalidDate5)
{
	EXPECT_THROW(
		{
			Date date;
			date.read(istringstream("0.10.2023"));
		},
		std::runtime_error);
}

TEST(TestInvalidDate6)
{
	EXPECT_THROW(
		{
			Date date;
			date.read(istringstream("a.b.2023"));
		},
		std::runtime_error);
}

TEST(TestValidDate1)
{
	Date date;
	date.read(istringstream("01.01.2000"));
	EXPECT_EQ(date.isDateCorrect(), true);
}

TEST(TestValidDate2)
{
	Date date;
	date.read(istringstream("09.09.2023"));
	EXPECT_EQ(date.isDateCorrect(), true);
}

TEST(TestValidDate3)
{
	Date date;
	date.read(istringstream("29.02.2022"));
	EXPECT_EQ(date.isDateCorrect(), true);
}

TEST(TestInvalidFileNameRead1)
{
	EXPECT_THROW(
	{
		FileInfo file_info;
		file_info.readNameFile(istringstream("tes?t.txt 28.02.2002 555"));
	},
	std::runtime_error);
}

TEST(TestInvalidFileNameRead2)
{
	EXPECT_THROW(
	{
		FileInfo file_info;
		file_info.readNameFile(istringstream("te\"st.txt 28.02.2002 555"));
	},
	std::runtime_error);
}

TEST(TestInvalidFileNameRead3)
{
	EXPECT_THROW(
	{
		FileInfo file_info;
		file_info.readNameFile(istringstream("*test*.txt 28.02.2002 555"));
	},
	std::runtime_error);
}

TEST(TestInvalidFileNameRead4)
{
	EXPECT_THROW(
		{
			FileInfo file_info;
			file_info.readNameFile(istringstream("tes/t.txt 28.02.2002 555"));
		},
		std::runtime_error);
}

TEST(TestValidFileNameRead1)
{
	FileInfo file_info;
	file_info.readNameFile(istringstream("test.txt 28.02.2002 555"));
	EXPECT_EQ(file_info.name_file, "test.txt");
}

TEST(TestValidFileNameRead2)
{
	FileInfo file_info;
	file_info.readNameFile(istringstream("TEST_123.txt 28.02.2002 555"));
	EXPECT_EQ(file_info.name_file, "TEST_123.txt");
}

TEST(TestValidFileNameRead3)
{
	FileInfo file_info;
	file_info.readNameFile(istringstream("999super_file_name999.txt 29.02.2002 555"));
	EXPECT_EQ(file_info.name_file, "999super_file_name999.txt");
}