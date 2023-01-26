import java.sql.*;

class testDatabase
{
    public static void main(String args[])throws Exception
    {
        String url = "jdbc:mysql://localhost:3306/users";
        String username = "rocky";
        String password = "";
        String query = "SELECT password FROM employees WHERE username=\"rocky\";";

        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection(url, username, password);
        Statement st = con.createStatement();
        ResultSet rs = st.executeQuery(query);

        rs.next();
        String res = rs.getString("password");
        System.out.println(res);

        st.close();
        con.close();
    }

}
