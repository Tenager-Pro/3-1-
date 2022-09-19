
<html>
    <head>
<meta charset="utf-8">
        <title>Россия 1</title>
        <link rel="icon" href="icon.ico" type="image/x-icon" >
        <link rel="stylesheet" href="style.css">
    </head>
    
 
 
    <body>
        
        <div class="header">
            <h1><a href="index.php">Россия 1</a></h1>
            
        
        </div>
        
        <div class="menu">
            
            <h1>Menu</h1>
            
                <ul>
                    <li><a href="#">Телепрограмма</a></li> 
                    <li><a href="company.html">О компании</a></li>
                    <li><a href="contact.html">Контакты</a></li>
                     
                </ul>
            <a href="authorithation.php">Войти</a>
        </div>
        
        <div class="list"> 
        <h1>Телепрограмма</h1>
        <?php
        $column = 3;
        $res = file_get_contents('teleprogram.json');
       
        $array = json_decode($res,true);
        
                echo '<table border="1" width="100%" cellpadding="5">';
                for ($i=0; $i < count($array); $i++) 
                {
                    
                    echo '<tr>';
                            echo '<td>'; echo $array[$i]['date']; echo '</td>';
                            echo '<td>'; echo $array[$i]['time']; echo ' </td>';
                            echo '<td>'; echo $array[$i]['name']; echo ' </td>';
                            echo '<td>'; echo $array[$i]['duration']; echo ' </td>';
                    echo '</tr>';
                }
                echo '</table><br>';
                    
        ?>
        <form action="#example_table2" method="post" class="example_form">
        <input type="string" name="date" placeholder=Date>
        <input type="string" name="time" placeholder=Time>
        <input type="string" name="name" placeholder=Name>
        <input type="string" name="duration"  placeholder=Duration>
        <input type="submit" name="submit" value="Добавить">
        </form>
        <?php
           
          
            
            
            if(isset($_POST['date'],$_POST['time'],$_POST['name'],$_POST['duration']))
            {
                $newArray=[
                    'date'=>$_POST['date'],
                    'time'=>$_POST['time'],
                    'name'=>$_POST['name'],
                    'duration'=>$_POST['duration'] 
                ]; 
                $array[]=$newArray;
                $encodeArr = json_encode($array);
                
                file_put_contents('teleprogram.json',$encodeArr);
            }
            
            
        ?>
                

            </div>
        </div>
        
        

    </body>
   



</html>
