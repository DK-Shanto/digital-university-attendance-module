<?php

include_once 'blade/view.file.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.file.inc';


?>

<table class="table table-striped">

    <?php


    //$Result = $_FileBAO->getAllFiles();
    $Result =  $_File_assignBAO->getAllFile_assigns();

    //if DAO access is successful to load all the Terms then show them one by one
    if($Result->getIsSuccess()){

        $FileAssignList = $Result->getResultObject();
        ?>
        <tr>

            <td>Creator</td>
            <td>To</td>
            <td>Download Link</td>
            <td>Discipline</td>
            <td>Comment</td>
            <td>Time</td>
        </tr>

        <?php
        for($i = 0; $i < sizeof($FileAssignList); $i++) {
            $FileAssign = $FileAssignList[$i];
            $File = $FileAssign->getFile();
            ?>
            <tr>
                <td>
                    <?php

                    if ($globalUser->getID() == $File->getCreator())
                    {
                        echo "<h5 style='color: #4CAF50' >Me</h5>";
                    }

                    else
                    {

                    $User = new user();
                    $User->setID($File->getCreator());
                    $User = $_UserBAO->readUser($User);
                    $User = $User->getResultObject();


                    echo $User->getFirstName() ." ". $User->getLastName(); }?>
                </td>


                <td><?php
                    $User = new user();
                    $User->setID($FileAssign->getReceiver());
                    $User = $_UserBAO->readUser($User);
                    $User = $User->getResultObject();


                    echo $User->getFirstName() ." ". $User->getLastName(); ?>
                </td>


                <td>

                    <a class="btn btn-primary" href="<?php echo "".$File->getLink(); ?>" role="button">Download</a>


                </td>

                <td><?php
                    /*
                    $Discipline = new discipline();
                    $Discipline->setID($File->getDiscipline());
                    $Discipline = $_DisciplineBAO->readDiscipline($Discipline);
                    $Discipline = $Discipline->getResultObject();
                    */
                    echo $FileAssign->getDiscipline() ?>

                </td>

                <td><?php
                    echo ($FileAssign->getFileComment());
                    /*
                    $Discipline = new discipline();
                    $Discipline->setID($File->getDiscipline());
                    $Discipline = $_DisciplineBAO->readDiscipline($Discipline);
                    $Discipline = $Discipline->getResultObject();
                    echo $Discipline->getName(); ?>
                    */ ?>

                </td>

                <td><?php
                    echo ($FileAssign->getTimestamp());
                    /*
                    $Discipline = new discipline();
                    $Discipline->setID($File->getDiscipline());
                    $Discipline = $_DisciplineBAO->readDiscipline($Discipline);
                    $Discipline = $Discipline->getResultObject();
                    echo $Discipline->getName(); ?>
                    */ ?>

                </td>

                <!-- <td><a href="?edit=<?php echo $File->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td> -->



                <!-- <td><a href="?del=<?php echo $File->getID(); ?>" class="badge badge-danger">Delete</a> -->
                </td>

                <td>
                    <a href="?history=<?php echo($File->getID());?>" class="badge badge-danger">History</a>
                </td>


            </tr>
            <?php

        }

    }
    else{

        echo $Result->getResultObject(); //giving failure message
    }

    ?>

</table>

<?php


if (isset($_GET['history']))
{
    $fileId = $_GET['history'];
    $File = new File();
    $File->setID($fileId);


    echo ("<table class=\"table table-striped\">");

    $Result =  $_File_assignBAO->getFileHistory($File);

    if($Result->getIsSuccess()){

        $FileAssignList = $Result->getResultObject();

        echo ("<tr>

            <td>Time</td>
            <td>Sender</td>
            <td>Receiver</td>
            <td>Links</td>
            <td>Comment</td>
            
        </tr>");

        for($i = 0; $i < sizeof($FileAssignList); $i++) {
            $FileAssign = $FileAssignList[$i];
            $File = $FileAssign->getFile();


            if ($i == sizeof($FileAssignList) - 1)
            {
                echo ("<tr style='background-color: #5cb85c'>");
            }

            else
            {
                echo ("<tr>");
            }

                 echo ("<td>");
                      //echo $FileAssign->getTimestamp();
                        $date = new DateTime($FileAssign->getTimestamp());
                        echo $date->format('h:i:s a m/d/Y') ;
                 echo ("</td>");


                echo ("<td>");

                        $User = new user();
                        $User->setID($FileAssign->getSender());
                        $User = $_UserBAO->readUser($User);
                        $User = $User->getResultObject();
                        echo $User->getFirstName() ." ". $User->getLastName();
                echo ("</td>");

                echo ("<td>");

                        $User = new user();
                        $User->setID($FileAssign->getReceiver());
                        $User = $_UserBAO->readUser($User);
                        $User = $User->getResultObject();
                        echo $User->getFirstName() ." ". $User->getLastName();
                echo ("</td>");


                echo ("<td>");


                             $fileLinks =  $FileAssign->getLinks();
                             $linksArray = explode(',',$fileLinks);
                             for ($j=0 ; $j < sizeof($linksArray) ; $j++)
                             {
                                 $link_and_creator = $linksArray[$j];
                                 $link_and_creator_and_time_array = explode(" ",$link_and_creator);

                                 $User = new user();
                                 $User->setID($link_and_creator_and_time_array[1]);
                                 $User = $_UserBAO->readUser($User);
                                 $User = $User->getResultObject();
                                 $userName =  $User->getFirstName() ." ". $User->getLastName();

                                 $time = $link_and_creator_and_time_array[2];
                                 date_default_timezone_set('Asia/Dhaka');

                                 echo ("<a target=\"_blank\" rel=\"noopener noreferrer\" href=");
                                 echo ('"'.$link_and_creator_and_time_array[0].'" ');

                                 if ($j==0)
                                 {
                                     echo ('data-toggle="tooltip" data-placement="top" title="Created by '.$userName.' on '.date('m/d/Y h:i:s a', $time).'"');
                                 }

                                 else
                                 {
                                     echo ('data-toggle="tooltip" data-placement="top" title="Appended by '.$userName.' on '.date('m/d/Y h:i:s a', $time).'"');
                                 }


                                 echo (">");

                                 echo ("<button type=\"button\" class=\"btn btn-default\" aria-label=\"Left Align\">
                                <span class=\"glyphicon glyphicon-paperclip\" aria-hidden=\"true\"></span>
                                </button>");

                                 echo ("</a>");

                             }


                        echo ("</a>");

                echo ("</td>");


                echo ("<td>");

                        echo $FileAssign->getFileComment();
                echo ("</td>");

            echo ("</tr>");


        }

    }
    else{

        echo $Result->getResultObject(); //giving failure message
    }


    echo ("</table>");


}
?>


<script>
    function alfun() {
        alert("Nothing");
    }
</script>

