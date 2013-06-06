#include <stan/math/matrix/log.hpp>
#include <gtest/gtest.h>
#include <stan/math/matrix/typedefs.hpp>
#include <stan/agrad/fwd/matrix/typedefs.hpp>
#include <stan/agrad/fvar.hpp>
#include <stan/agrad/var.hpp>
#include <test/agrad/util.hpp>

TEST(AgradFwdMatrix, log_matrix) {
  using stan::math::log;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;

  matrix_d expected_output(2,2);
  matrix_fv mv(2,2), output;
  int i,j;

  mv << 1, 2, 3, 4;
   mv(0,0).d_ = 1.0;
   mv(1,0).d_ = 1.0;
   mv(0,1).d_ = 1.0;
   mv(1,1).d_ = 1.0;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      EXPECT_FLOAT_EQ(expected_output(i,j), output(i,j).val_);
  EXPECT_FLOAT_EQ(1, output(0,0).d_);
  EXPECT_FLOAT_EQ(0.5, output(0,1).d_);
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(1,0).d_);
  EXPECT_FLOAT_EQ(0.25, output(1,1).d_);
}

TEST(AgradFwdMatrix, log_vector) {
  using stan::math::log;
  using stan::math::vector_d;
  using stan::agrad::vector_fv;

  vector_d expected_output(4);
  vector_fv mv(4), output;

  mv << 1, 2, 3, 4;
   mv(0).d_ = 1.0;
   mv(1).d_ = 1.0;
   mv(2).d_ = 1.0;
   mv(3).d_ = 1.0;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (int i = 0; i < 4; i++)
    EXPECT_FLOAT_EQ(expected_output(i), output(i).val_);
  EXPECT_FLOAT_EQ(1, output(0).d_);
  EXPECT_FLOAT_EQ(0.5, output(1).d_);
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(2).d_);
  EXPECT_FLOAT_EQ(0.25, output(3).d_);
}

TEST(AgradFwdMatrix, log_rowvector) {
  using stan::math::log;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fv;

  row_vector_d expected_output(4);
  row_vector_fv mv(4), output;

  mv << 1, 2, 3, 4;
   mv(0).d_ = 1.0;
   mv(1).d_ = 1.0;
   mv(2).d_ = 1.0;
   mv(3).d_ = 1.0;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (int i = 0; i < 4; i++)
    EXPECT_FLOAT_EQ(expected_output(i), output(i).val_);
  EXPECT_FLOAT_EQ(1, output(0).d_);
  EXPECT_FLOAT_EQ(0.5, output(1).d_);
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(2).d_);
  EXPECT_FLOAT_EQ(0.25, output(3).d_);
}
TEST(AgradFwdFvarVarMatrix, log_matrix) {
  using stan::math::log;
  using stan::math::matrix_d;
  using stan::agrad::matrix_fvv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(1.0,1.0);
  fvar<var> b(2.0,1.0);
  fvar<var> c(3.0,1.0);
  fvar<var> d(4.0,1.0);

  matrix_d expected_output(2,2);
  matrix_fvv mv(2,2), output;
  int i,j;

  mv << a,b,c,d;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      EXPECT_FLOAT_EQ(expected_output(i,j), output(i,j).val_.val());
  EXPECT_FLOAT_EQ(1, output(0,0).d_.val());
  EXPECT_FLOAT_EQ(0.5, output(0,1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(1,0).d_.val());
  EXPECT_FLOAT_EQ(0.25, output(1,1).d_.val());
}

TEST(AgradFwdFvarVarMatrix, log_vector) {
  using stan::math::log;
  using stan::math::vector_d;
  using stan::agrad::vector_fvv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(1.0,1.0);
  fvar<var> b(2.0,1.0);
  fvar<var> c(3.0,1.0);
  fvar<var> d(4.0,1.0);

  vector_d expected_output(4);
  vector_fvv mv(4), output;

  mv << a,b,c,d;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (int i = 0; i < 4; i++)
    EXPECT_FLOAT_EQ(expected_output(i), output(i).val_.val());
  EXPECT_FLOAT_EQ(1, output(0).d_.val());
  EXPECT_FLOAT_EQ(0.5, output(1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(2).d_.val());
  EXPECT_FLOAT_EQ(0.25, output(3).d_.val());
}

TEST(AgradFwdFvarVarMatrix, log_rowvector) {
  using stan::math::log;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fvv;
  using stan::agrad::fvar;
  using stan::agrad::var;

  fvar<var> a(1.0,1.0);
  fvar<var> b(2.0,1.0);
  fvar<var> c(3.0,1.0);
  fvar<var> d(4.0,1.0);

  row_vector_d expected_output(4);
  row_vector_fvv mv(4), output;

  mv << a,b,c,d;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (int i = 0; i < 4; i++)
    EXPECT_FLOAT_EQ(expected_output(i), output(i).val_.val());
  EXPECT_FLOAT_EQ(1, output(0).d_.val());
  EXPECT_FLOAT_EQ(0.5, output(1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(2).d_.val());
  EXPECT_FLOAT_EQ(0.25, output(3).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, log_matrix) {
  using stan::math::log;
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffv;
  using stan::agrad::fvar;

  fvar<fvar<double> > a,b,c,d;
  a.val_.val_ = 1.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 2.0;
  b.d_.val_ = 1.0;
  c.val_.val_ = 3.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 4.0;
  d.d_.val_ = 1.0; 

  matrix_d expected_output(2,2);
  matrix_ffv mv(2,2), output;
  int i,j;

  mv << a,b,c,d;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      EXPECT_FLOAT_EQ(expected_output(i,j), output(i,j).val_.val());
  EXPECT_FLOAT_EQ(1, output(0,0).d_.val());
  EXPECT_FLOAT_EQ(0.5, output(0,1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(1,0).d_.val());
  EXPECT_FLOAT_EQ(0.25, output(1,1).d_.val());
}

TEST(AgradFwdFvarFvarMatrix, log_vector) {
  using stan::math::log;
  using stan::math::vector_d;
  using stan::agrad::vector_ffv;
  using stan::agrad::fvar;

  fvar<fvar<double> > a,b,c,d;
  a.val_.val_ = 1.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 2.0;
  b.d_.val_ = 1.0;
  c.val_.val_ = 3.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 4.0;
  d.d_.val_ = 1.0; 

  vector_d expected_output(4);
  vector_ffv mv(4), output;

  mv << a,b,c,d;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (int i = 0; i < 4; i++)
    EXPECT_FLOAT_EQ(expected_output(i), output(i).val_.val());
  EXPECT_FLOAT_EQ(1, output(0).d_.val());
  EXPECT_FLOAT_EQ(0.5, output(1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(2).d_.val());
  EXPECT_FLOAT_EQ(0.25, output(3).d_.val());
}

TEST(AgradFwdFvarFvarMatrix, log_rowvector) {
  using stan::math::log;
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_ffv;
  using stan::agrad::fvar;

  fvar<fvar<double> > a,b,c,d;
  a.val_.val_ = 1.0;
  a.d_.val_ = 1.0;  
  b.val_.val_ = 2.0;
  b.d_.val_ = 1.0;
  c.val_.val_ = 3.0;
  c.d_.val_ = 1.0;
  d.val_.val_ = 4.0;
  d.d_.val_ = 1.0; 

  row_vector_d expected_output(4);
  row_vector_ffv mv(4), output;

  mv << a,b,c,d;
  expected_output << std::log(1), std::log(2), std::log(3), std::log(4);
  output = log(mv);

  for (int i = 0; i < 4; i++)
    EXPECT_FLOAT_EQ(expected_output(i), output(i).val_.val());
  EXPECT_FLOAT_EQ(1, output(0).d_.val());
  EXPECT_FLOAT_EQ(0.5, output(1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 3.0, output(2).d_.val());
  EXPECT_FLOAT_EQ(0.25, output(3).d_.val());
}
