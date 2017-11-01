#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> mat1(2);
	mat1[0][1] = 1;

	TMatrix<int> mat2(mat1);
	EXPECT_EQ(mat1, mat2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> mat1(2);
	mat1[0][1];

	TMatrix<int> mat2(mat1);
	EXPECT_NE(&mat1[0], &mat2[0]);
}

TEST(TMatrix, can_get_size)
{
	const int size = 2;
	TMatrix<int> mat1(size);
	
	EXPECT_EQ(size, mat1.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> mat1(2);
	TVector<int> v(2);
	v[1] = 2;
	mat1[0] = v;

	EXPECT_EQ(v, mat1[0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> mat1(2);
	TVector<int> v(2);

	ASSERT_ANY_THROW(mat1[-1] = v);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	const int maxsize = 100;
	TMatrix<int> mat1(maxsize);
	TVector<int> v(maxsize);
	v[1] = 3;

	ASSERT_ANY_THROW(mat1[maxsize + 1] = v);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> mat1(10), tmp(10);
	mat1[0][1] = 2;

	tmp = mat1;
	tmp = tmp;

	EXPECT_EQ(mat1, tmp);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 3;
	TMatrix<int> m1(size), m2(size);
	m1[0][1] = 3;

	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(2), m2(3);
	m1[1][1] = 2;

	m2 = m1;
	EXPECT_EQ(2, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(2), m2(3);
	m1[1][1] = 2;

	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(2), m2(2);
	m1[1][1] = 2;

	m2 = m1;
	EXPECT_TRUE(m2 == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(2);
	m1[0][1] = 2;

	EXPECT_TRUE(m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(2), m2(3);
	m1[1][1] = 2;
	m2[1][1] = 2;

	EXPECT_FALSE(m2 == m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(2), m2(2), exp(2);
	m1[0][0] = 1;
	m1[0][1] = 3;
	//m1[1][0] = 4;
	m1[1][1] = 2;

	m2[0][0] = 1;
	m2[0][1] = 3;
	//m2[1][0] = 1;
	m2[1][1] = 5;

	exp[0][0] = 2;
	exp[0][1] = 6;
	//exp[1][0] = 5;
	exp[1][1] = 7;

	m1 = m1 + m2;

	EXPECT_EQ(exp, m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(2), m2(3);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(2), m2(2), exp(2);
	m1[0][0] = 1;
	m1[0][1] = 3;
	//m1[1][0] = 4;
	m1[1][1] = 2;

	m2[0][0] = 1;
	m2[0][1] = 3;
	//m2[1][0] = 1;
	m2[1][1] = 5;

	exp[0][0] = 0;
	exp[0][1] = 0;
	//exp[1][0] = 3;
	exp[1][1] = -3;

	m1 = m1 - m2;

	EXPECT_EQ(exp, m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(2), m2(3);

	ASSERT_ANY_THROW(m1 - m2);
}

