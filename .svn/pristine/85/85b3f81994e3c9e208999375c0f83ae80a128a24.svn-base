<?php

include_once 'blade/view.notification.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.file.inc';

?>





<div class="container">
    <div class="row">
        <div class="col-sm">




            <table class="table table-hover table-dark">

                <?php


                $Result = $_File_assignBAO->getAllReceivedFile_assigns();

                //if DAO access is successful to load all the Terms then show them one by one
                if($Result->getIsSuccess()){

                    $FileAssignList = $Result->getResultObject();
                ?>



                <thead>
                <tr>
                    <th scope="col">#</th>
                    <th scope="col">From</th>
                    <th scope="col">Time</th>

                </tr>
                </thead>


                <tbody>

                <?php
                for($i = 0; $i < sizeof($FileAssignList); $i++) {
                    $FileAssign = $FileAssignList[$i];
                    $File = $FileAssign->getFile();
                ?>
                <tr>
                    <th scope="row"><?php echo ($i+1);?></th>
                    <td><?php
                        $User = new user();
                        $User->setID($FileAssign->getSender());
                        $User = $_UserBAO->readUser($User);
                        $User = $User->getResultObject();


                        echo $User->getFirstName() ." ". $User->getLastName(); ?>
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

                    <td
                        ><button type="button" onclick="testFun(this.name)" class="btn btn-primary" name="<?php echo $File->getID().",".$File->getCurrentUser();  ?>  ">Detail</button>
                    </td>

                    <td>
                        <a href="?history=<?php echo($File->getID());?>" class="badge badge-danger">History</a>
                    </td>

                </tr>

                </tbody>

                    <?php

                }

                }
                else{

                    echo $Result->getResultObject(); //giving failure message
                }

                ?>
            </table>



        </div>
        <div class="col-sm">

            <table class="table table-hover table-dark">

                <tbody>
                <tr>
                    <td>Sender</td>
                    <td id="sender"><p id="test">  </p></td>

                </tr>
                <tr>

                    <td>Discipline</td>
                    <td id="discipline"></td>

                </tr>
                <tr>

                    <td>Comment</td>
                    <td id="comment"></td>

                </tr>
                <tr>

                    <td>Time</td>
                    <td id="time"></td>

                </tr>

                <tr>
                    <td>
                        <input type="text" name="fileLinks" id="fileLinks" style="display:none" value="nothing">
                    </td>

                </tr>

                </tbody>

            </table>
            <a  id="downloadButton" href="#" class="btn btn-primary btn-lg active" role="button" aria-pressed="true">Download</a>

            <button type="button" class="btn btn-primary" onclick="myFunction()">Forward</button>


            <script>
                function myFunction() {
                    //alert(document.getElementById("form").style.display);
                    if(document.getElementById("form").style.display == "none")
                    {
                        document.getElementById("form").style.display="block";
                    }
                    else
                    {
                        document.getElementById("form").style.display="none";
                    }

                }
            </script>


        </div>

        <div class="col-sm">

            <div id="form" style="display: none">
                <form method="post" enctype="multipart/form-data">
                    <table width="100%" border="1" cellpadding="15">
                        <tr>
                            <td>
                                <h3>To</h3>
                            </td>

                            <td>
                                <select name="users">
                                    <?php $Result = $_UserBAO->getAllUsers();

                                    //if DAO access is successful to load all the Disciplines then show them one by one
                                    if($Result->getIsSuccess()){

                                        $UserList = $Result->getResultObject();


                                        for($i = 0; $i < sizeof($UserList); $i++) {
                                            $User = $UserList[$i];
                                            # code...?>

                                            <option value="<?php echo $User->getID(); ?>">
                                                <?php echo $User->getFirstName() ." ". $User->getLastName(); ?>
                                            </option> <?php
                                        }
                                    }
                                    else{

                                        echo $Result->getResultObject(); //giving failure message

                                    }
                                    ?>
                                </select>
                            </td>
                        </tr>

                        <tr>
                            <td>
                                <h3>Comments</h3>
                            </td>
                            <td>
                                <input type="text" name="Comment" id="Comment">
                            </td>
                        </tr>

                        <tr>
                            <td>
                                <h3>Attachment</h3>
                            </td>
                            <td>
                                <!-- <input type="file" name="link" id="linkId"> -->


                                <input type="file" name="fileToUpload" id="fileToUpload">

                            </td>
                        </tr>


                        <tr>
                            <td>
                                <input type="text" name="fileId" id="fileId" style="display:none" value="nothing">
                            </td>
                        </tr>

                        <tr>
                            <td>
                                <input type="text" name="fileIdLinks" id="fileIdLinks" style="display:none " value="nothing">
                            </td>
                        </tr>

                        <tr>
                            <td>
                                <button type="submit" name="forward">Forward</button>
                            </td>
                        </tr>
                    </table>
                </form>

                <br />
            </div>

        </div>



    </div>
</div>





<script>


    function testFun(id) {

         var result = id.split(',');


        //alert(result[1]);




        //document.getElementById("sender").innerHTML = "Nothing";

        $.ajax(
            { url: 'modules/file/ui/test.php',
                data: {fileid: result[0], userId: result[1]},
                type: 'get',
                success: function(output) {


                    //alert(output);


                    var jsonData = JSON.parse(output);

                    var l = jsonData.length;
                    var i = l-1;

                    var name  = jsonData[i].FirstName + ' '+jsonData[i].LastName;
                    var discipline = jsonData[i].DispName;
                    var  comment = jsonData[i].comment;
                    var time = jsonData[i].timestamp;
                    var link = jsonData[i].Link;
                    var links = jsonData[i].links;

                    //alert(links);

                    document.getElementById("sender").innerHTML = name;
                    document.getElementById("discipline").innerHTML = discipline;
                    document.getElementById("comment").innerHTML = comment;
                    //document.getElementById("comment").innerHTML = output;

                    document.getElementById("time").innerHTML = time;
                    document.getElementById("downloadButton").href = link;
                    document.getElementById("fileLinks").value = links;
                    document.getElementById("fileIdLinks").value = links;
                    document.getElementById("fileId").value = result[0];



                }
            });




    }

</script>


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