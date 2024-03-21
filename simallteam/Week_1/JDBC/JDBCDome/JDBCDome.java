package com.QG.jdbc;

import java.util.Scanner;

public class JDBCDome {
    public static void main(String[] args) throws Exception{

        String sqlUpdate = "update massage set money = ? where id = ?";
        String sqlInsert = "insert into massage values(?,?,?)";
        String sqlDelete = "delete from massage where id = ?" ;

        //update 更新
        //insert into 表 values(值1，值2)
        //delete 删除
        //de1ete from 表名 [where 条件],删除内容;

        Object[] xInsert = new Object[3];
        Object[] xUpdate = new Object[2];
        Object[] xDelete = new Object[1];
        //插入的参数

        /*
        表名是massage
        我创建的表的格式是
        money name      id(类型是char)
        1000  zhangsan  1
        1000  lisi      2

         */




        System.out.println("请选择功能,1.增加 2.删 3.改");
        Scanner sc = new Scanner(System.in);
        int choose = sc.nextInt();

        switch(choose)
        {
            case 1: //增加
                System.out.println("请依次输入 money name 和 id");
               for (int i = 0; i < 3 ; i++) {
                   xInsert[i] = sc.next();
               }
               if(1 == JDBCUtil.upDate(sqlInsert,xInsert)) //检验是否运行成功
               {
                   System.out.println("加入成功");
               }
               break;

            case 2: //删除
                System.out.println("请输入要删除的序号");
                xDelete[0] = sc.next();

                if(1 == JDBCUtil.upDate(sqlDelete,xDelete))
                {
                    System.out.println("删除成功");//检验是否运行成功
                }
                break;

            case 3: //更改
                System.out.println("请输入要更改的钱数和对应的id");
                for (int i = 0; i <2; i++) {
                    xUpdate[i] = sc.next();
                }

                if(1 == JDBCUtil.upDate(sqlUpdate,xUpdate))
                {
                    System.out.println("更改成功");//检验是否运行成功
                }

                break;

        }

    }
}
