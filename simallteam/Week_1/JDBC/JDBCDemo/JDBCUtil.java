package com.QG.jdbc;


import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class JDBCUtil {


    private static String url;
    private static String username;
    private static String password;
    private static String driver;



    //运行一次
    //加载驱动
    static{
        Properties property = new Properties();
        try {

            //获取文件
            try {
                property.load(new FileInputStream("D:\\java\\java_code\\QGwork_1\\JDBCDome\\src\\com\\QG\\jdbc\\java.properties"));
                //本人properties文件地址

            } catch (IOException e) {
                throw new RuntimeException(e);
            }



            url = property.getProperty("url");
            password = property.getProperty("password");
            driver = property.getProperty("driver");
            username = property.getProperty("username");


            Class.forName(driver);
            //这里用的驱动版本为8.0.24，从mysql-connector-java 5版本后jdbc.driver已经失效，
            //因此使用新版driver，路径应该为：com.mysql.cj.jdbc.Driver

        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }


/*创建链接
getConn()
返回Connection
*/
    public static Connection getConn()
    {
        Connection conn;
        try {
             conn = DriverManager.getConnection(url,username,password);

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return conn; //返回链接
    }




    //增删改的封装
    //返回值是0，修改失败
    //是0以外的数修改成功
    //数组是?号占位符,所有不确定的数用?来表示

//Object[] params 是sql ? 所代表的参数
  public static int upDate(String sql,Object[] params ){
        Connection conn = getConn();
         PreparedStatement ps = null;
      try {

          ps = conn.prepareStatement(sql);  //获取执行sql参数

          setParma(ps,params);  //设置参数

        return ps.executeUpdate(); //返回影响的函数


      } catch (SQLException e) {
          throw new RuntimeException(e);
      }finally {
          close(null,ps,conn);
      }

  }



  //封装设置参数的方法
    public static void setParma(PreparedStatement ps ,Object[] params)
    {
        //遍历params 数组

        try {


            if(params != null)
            {
                for (int i = 0; i < params.length; i++) {
                    ps.setObject(i+1,params[i]);  //设置参数,按循序赋值
                }
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }


    // DML的执行不产生ResultSet结果集，可以传入一个null;
    // 因此要先判断传入的对象是否为空，若非空则调用close方法关闭资源（动态绑定）
    //关闭
    public static void close( ResultSet set,PreparedStatement ps,Connection conn)
    {

            try {

                if (set != null) {
                set.close();
            }

                if (ps != null) {
                    ps.close();
                }

                if (conn != null) {
                    conn.close();
                }



            } catch (SQLException e) {
                throw new RuntimeException(e);
            }

    }

}
