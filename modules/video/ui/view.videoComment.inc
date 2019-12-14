<?php

include_once 'blade/view.VideoComment.blade.inc';
include_once 'blade/view.videosearch.blade.inc';
include_once MODULES_VIDEO.'bao/class.videoCommentbao.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';


//view count 


?>





<div class="panel panel-default"> <?php //1st div >  ?>
	

	<div class="container">
			<div class="well well-sm">
      <!-- Portfolio Item Heading -->
      <h7 class="my-4">Video Viewer
        <small>-Khulna University </small>
      </h7>
  </div>

      <!-- Portfolio Item Row -->
      <div class="row">

        <div class="col-md-8">
         

         <!-- <img class="img-fluid" src="http://placehold.it/750x500" alt="">  -->
        
				
	<!-- <div class="panel-heading">Video Tutorial Viewer</div>  <?php // 2nd div >  ?> -->

	 			
	 <div  style="overflow: auto;padding: -100px 100px;  >  <?php //3rd div >  ?>
	 	 <div id="video">  <?php //4th div >  ?>


	 	 		

	 	 	<?php


	 	 	//ekhane problem 
				$id = 'http://'.$_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI'];
				$Video2 = substr($id, -38);
				$Result1 = $_VideoCommentBAO->readvideo($Video2);



				
				

				//if DAO access is successful to load all the comments then show them one by one
				if($Result1->getIsSuccess()){ // 1st if start 
/*
				$_VideoCommentBAO->updateViews($Video2);*/

				$Vedio = $Result1->getResultObject();
			?> 
			
			
			

			<div>
				<?php
					$front = '<iframe width="750" height="500" src="https://www.youtube.com/embed/' ;
					$back = '" frameborder="0" allowfullscreen></iframe>';
					$link = $Vedio->getLink();
					$link_ID = substr($link, -11);

					//$link2= substr($link);
					$Link=$front.$link_ID.$back;
					echo $Link; 
				?>
			</div>
			<?php
				}
				else{
				echo $Result->getResultObject(); //giving failure message //1st if close 
				}
			?>
		</br>
		<div class= "well well-lg" >
				
              	 <h5 style="color: red;font-size: large; font-family: " ><?php echo "Video Title : ".$Vedio->getTitle(); ?></h5> 

              	 <h5 style="color:green "><?php echo "Description : ".$Vedio->getDescription(); ?></h5> 




<?php 
			$id1= $Vedio->getCreatorID();
			$Result55 = $_VideoCommentBAO->readCreator($id1);
			
				
						
			if ($Result55->getIsSuccess() ) {
				$user1 = $Result55->getResultObject();
?>

      		<h5 style="color: red;font-size: medium;" ><?php echo "Creator Name : ".$user1->getFirstName().' '.$user1->getLastName().'';
							    			} 
		?>	</h5>


				 <!--  <h5 style="color: purple;font-size: medium;" ><?php echo "Views : ".$Vedio->getViews(); ?></h5> 
 -->
              	  <h5 style="color: purple;font-size: medium;" ><?php echo "Creator's Email : ".$Vedio->getCreatorID(); ?></h5> 


              	   <h5 style="color:purple" ><?php echo "Creation Date : ".$Vedio->getCreationDate(); ?></h5> 
              	 <!--  <h5  ><?php echo "Link : ".$Vedio->getLink(); ?></h5> -->
              	 
              	


			</div>
				</div>
			</div>




			<!--playlis div start-->
				<div class="col-md-4" style = "max-width: 500px;height:500px;position: relative;">
						<div id="form" >
<form method = "post"class="form-inline mr-auto">
  <input class="form-control mr-sm-2" name ="txtsearch" type="text" placeholder="Search" aria-label="Search"style="width: 350px;">
  <i class="fa fa-search" aria-hidden="true"></i>
  <button class="btn btn-outline-success btn-rounded btn-sm my-0" style="right:-50px;width: 100px;"type="submit" id="savebutton" name="search" value="search">Search</button>
  
</br></br></br>
</form>

	</div>

					<div class="well well-sm" style ="max-width: 600px;height:50px;color: red" >
          	Related Videos  
          			 </div>

          			 
          		<div class="col-md-4" style = "right:10px;min-width: 500px ; max-width : 500px;height:500px;position: relative; overflow-x: hidden">	 

			
<table class="table table-striped">
	
	<?php
	
	
	
	$Result = $_VideoCommentBAO->relatedVideo($Vedio->getTag(),$Vedio->getID(),$Vedio->getTitle());

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$VideoList = $Result->getResultObject();

	?>
		<?php
		for($i = 0; $i < sizeof($VideoList); $i++) {
			$Video = $VideoList[$i];
			?>
		    <tr>
			    <td>
			    <a href="video_comment.php?view=<?php echo $Video->getID(); ?>" onclick="return ; " >

			    <?php 
			    		$id3=$Video->getCreatorID();
			    		$resultRelated=$_VideoCommentBAO->readCreator($id3);
			    		if ($resultRelated->getIsSuccess() ) {
						$user2 = $resultRelated->getResultObject();


			    		echo $Video->getTitle()."</br>"; 

			    		echo "Tag : ".$Video->getTag()."</br>"; 
			    		echo "Creator : ".$user2->getFirstName().' '.$user2->getLastName()."</br>"; 

			    		echo "Creator : ".$Video->getCreationDate()."</br>"; 
}

			    						?>

			    	
			    </a>
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






          			 </div>
          		<div class="col-md-4" style = "min-width: 500px ; max-width : 500px;height:500px;position: relative; overflow-x: hidden">	 
          				
         <!-- 	<a href="video_search.php" style="color: red" onclick="return ; " >Search Video  </a> -->

         	
		<a style ="color: red;" href="video.php" onclick="return ; " >Upload a Video </a>

				</div>
				
					 
						
          			 </div>

		</div>  <!--upload div end -->

					
				</div>
				
					 
					

		</div>  <!--playlist div end -->


		





       








		<?Php // 4th div close  // video div end comment box start ; //comment correction 17-09
//https://www.facebook.com/Rk.romankhan.903/videos/1001166663388200/
//https://www.facebook.com/toidicode/videos/543922712725727/
?>


<?php /* problem 
 <iframe src="https://www.facebook.com/plugins/video.php?href=https%3A%2F%2Fwww.facebook.com%2Ftoidicode%2Fvideos%2F543922712725727%2F&show_text=0&width=560" width="560" height="315" style="border:none;overflow:hidden" scrolling="no" frameborder="0" allowTransparency="true" allowFullScreen="true"></iframe>
<iframe src="https://www.facebook.com/plugins/video.php?href=https%3A%2F%2Fwww.facebook.com%2FRk.romankhan.903%2Fvideos%2F1001166663388200%2F&show_text=0&width=560" width="560" height="420" style="border:none;overflow:hidden" scrolling="no" frameborder="0" allowTransparency="true" allowFullScreen="true"></iframe>
*/
?>

		<div id = comment-box> <?php //1st cmnt post box div > ?>
			
		 	<form method="post" class="panel panel-info" >
		 		<input type='text' name ="txtvideo" value="<?php echo $Video2 ; ?>" placeholder="<?php echo $Video2 ; ?>"" style="display : none" />

		 		<div id = "comment"class="panel-heading" style="display: block;">Add a public comment</div>
		 		<div id ="txtcomment" class="panel-body">

		 				<div class="form-group">
            <!--   	<label class="control-label col-sm-4" for="txtlink">Comment:</label> -->
              	<div class="col-sm-8">  
              		
				<input type="text" name="txtComment" class="form-control input-lg"  placeholder="Write your comment here" value="<?php
					
					if(isset($_GET['edit'])){
						$link = $getROW->getVideo();
						echo $link;
						} ?>" required />
				</div>
					
</div>
					<!-- <textarea class="form-control" name="txtComment" 
					value="<?php if(isset($_GET['edit'])) echo $getROW->getVideo();  ?>"  required>
					</textarea> -->
<div class="form-group">

					<input type="hidden" name="CreatorID" value="<?php if(isset($_GET['edit'])) echo $getROW->getCreatorID();  ?>" />
					</div>
					<div class="form-group">

					<input type="hidden" name="videoID" value="<?php if(isset($_GET['edit'])) echo $getROW->getVideoID();  ?>" />
					</div>

				<!-- 	<div class="form-group">
					
					<input class="btn btn-success btn-sm"  type="submit" id="savebutton"  name="save" value="Comment">
					</div>
				</div> -->
		


				 <div class="form-group">        
	              <div class="col-sm-offset-4 col-sm-4">					
	</br>
						<?php
						if(isset($_GET['edit']))
						{
							?>
							<input  type="submit" id="savebutton" name="update" value="Update">
							<?php
						}
						else
						{
							?>
							<input class="btn btn-success btn-sm"  type="submit"  id="savebutton" name="save" value="Comment">
							<?php
						}
						?>
					</div>
				</div>	
			</div>

	</form>
<!-- This is for reply box -->
	<!-- extra	 -->		
<form method="post" class="panel panel-info" >

<!-- extra	 -->			
		<div id = "reply" class= "panel-heading" style="display: none;" >Add a public reply</div>
				<div id =reply_txt style="display: none;" class="panel-body">


		 				<div class="form-group">

            <!--   	<label class="control-label col-sm-4" for="txtlink">Comment:</label> -->
              	<div class="col-lg-10">  
              		
				<input type="text" name="txtReply" class="form-control input-lg"  placeholder="Write your reply here" value="<?php
					
					if(isset($_GET['edit'])){
						$link = $getROW->getVideo();
						echo $link;
						} ?>"  required/>
				</div>
					
</div>

					<!-- <textarea class="form-control" name="txtReply" 
					value="<?php if(isset($_GET['edit'])) echo $getROW->getVideo();  ?>" >
					</textarea> -->
					<div class="form-group">
					<input type="hidden" name="Reply_CreatorID" value="<?php if(isset($_GET['edit'])) echo $getROW->getCreatorID();  ?>" />
					</div>
					<div class="form-group">
					<input type="hidden" name="Reply_videoID" value="<?php if(isset($_GET['edit'])) echo $getROW->getVideoID();  ?>" />
					</div>
					<div class="form-group">
					<input type="hidden" id="CommentID" name="CommentID" value="<?php if(isset($_GET['edit'])) echo $getROW->getCommentID();  ?>" />
						</div>


				 <div class="form-group">        
	              <div class="col-sm-offset-4 col-sm-4">					
	</br>
						<?php
						if(isset($_GET['edit']))
						{
							?>
							<input  type="submit" id="replysavebutton" name="update" value="Update">
							<?php
						}
						else
						{
							?>
							<input class="btn btn-success btn-sm"  type="submit"  id="replysavebutton" name="save2" value="Reply">
							<?php
						}
						?>
					</div>
				</div>	
					<!-- </br>
					<input class="btn btn-success btn-sm"  type="submit" id="replysavebutton"  name="save2" value="Reply"> -->
				</div>


<!-- extra		 -->	

   <!--  exrta	 -->
			</form>
		</div> <?php //1st cmnt post box end ?>







<script>
	$(function(){
    $("button").click(function() {
        document.getElementById("CommentID").value = $(this).val();
    });
});
function myFunction() {
    var x = document.getElementById("reply");
    var y=document.getElementById("reply_txt");
    var c1=document.getElementById("comment");
    var c2=document.getElementById("txtcomment");
    if (x.style.display === "none") {
        x.style.display = "block";
        y.style.display="block";
        c1.style.display = "none";
        c2.style.display="none";

        
    } else {
        x.style.display = "none";
        y.style.display = "none";
        c1.style.display = "block";
        c2.style.display="block";
    }
}
</script>












		<div class="panel panel-success"> <?php // rc div 1 ?>
      		<div class="panel-heading">Recent comments</div> 
		</div>  <?php // rc div 1 end ?>

		<?php 
			//all comment fetch 
			$id = 'http://'.$_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI'];
			$Video2 = substr($id, -38);
			//echo $Video2;	
			$Result1 = $_VideoCommentBAO->readVideoComment($Video2);
			


			//if DAO access is successful to load all the comments then show them one by one
			if($Result1->getIsSuccess()){
			$VideoList = $Result1->getResultObject();
			// var_dump(sizeof($VideoList));
			for($i = 0; $i < sizeof($VideoList); $i++) {
				$Video = $VideoList[$i];
?>											
				<div class="panel-heading" style="font-size:12px;font-weight:bold ;position: relative; left: 0px; width:545px;">	


		<?php 
			$id= $Video->getCreatorID();
			$Result5 = $_VideoCommentBAO->readCreator($id);
			
				
						
			if ($Result5->getIsSuccess() ) {
				$user = $Result5->getResultObject();
?>
	<div class="panel panel-primary"style ="position: relative; left: 10px; width:545px;"> <?php // rc div 1 ?>
      		<div class="panel-heading">
		<?php
				echo $user->getFirstName().' '.$user->getLastName().'     '.$Video->getCreationDate();
							    			} 
		?>		</div> </div>
				<div style ="position: relative; left: 10px; width:1090px;"  class="panel panel-success">
					<?php
						
							echo ' '.$Video->getComment();
						
						

					//calss.common.forum.inc er last a ase  
					?>
					<input type="hidden" name="comment_id" id="comment_id"value="<?php echo($Video->getCommentID()); ?>">
					<br/>
					<button type="button" onclick="myFunction(this)" href="#reply" value="<?php echo($Video->getCommentID()); ?>" class="btn btn-link">Reply</button>




					

				</div>

				<?php

				$Res = $_VideoCommentBAO->readVideoReply($Video->getCommentID())->getResultObject();
				// var_dump($Res);
				$ResultForReply = $_VideoCommentBAO->readVideoReply($Video->getCommentID());
				$replyList=$ResultForReply->getResultObject();
					$count=0;
				foreach ($Res as $row) {
					$comment_=$replyList[$count];
					$count++;
					$crid=$row->getCreatorID();
					$Result_crid = $_VideoCommentBAO->readCreator($crid);
					if ($Result_crid->getIsSuccess() ) {
					$crtr = $Result_crid->getResultObject();
					$sum=100+$count*50;
					$sum2=1000-$count*50;

?>
	<div class="panel panel-info"style ="position: relative; left: <?php echo $sum.'px'?>; width:455px;" > <?php // rc div 1 ?>
      		<div class="panel-heading">
		<?php
		//problem is here 
// for reply 
				echo '     '.$crtr->getFirstName().' '.$crtr->getLastName().'  '.$comment_->getCreationDate();
							    			} 

					//echo ($row->getCreatorID());
					?>
				</div></div>

			<div style ="position: relative; left: <?php echo $sum.'px'?>; width:<?php echo $sum2.'px'?>;"  class="panel panel-success">
				<?php
				// var_dump($row);
				echo '    '.($row->getComment());

				?>
				<input type="hidden" name="comment_id" id="comment_id"value="<?php echo($Video->getCommentID()); ?>">
					<br/>
					<button type="button" onclick="myFunction(this)" href="#reply" value="<?php echo($Video->getCommentID()); ?>" class="btn btn-link">Reply</button> 

					

					
			</br>
				
				</div>
					<?php
				}
				?>
	
<?php
}
}
	else
	{
		echo $Result->getResultObject();
	}


						
								?>
									 


	<!-- 	  //comment box er div  -->



		
</div>  <!-- //panel body er div 
 -->
</div> <!-- //last panel er div ?> 
 -->
</div>

